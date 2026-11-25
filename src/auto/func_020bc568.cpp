#include "m2c.h"

struct Step {
    s32 v;
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

struct Vec3 {
    s32 x, y, z;
};

class Res {
public:
    virtual void m0();
    virtual void m1();
    virtual void release();
    u8 pad04[8];
    s32 refs;   /* 0x0c */
    s32 refs2;  /* 0x10 */
    u8 locked;  /* 0x14 */
};

struct Item {
    u8 pad00[0x24];
    Vec3 pos;           /* 0x24 */
    u8 pad30[0x15];
    u8 dirty;           /* 0x45 */
    u8 pad46[2];
    s32 owner;          /* 0x48 */
    u8 pad4c[4];
    Res *res;           /* 0x50 */
    Vec3 vel;           /* 0x54 */
    u8 pad60[0x10];
    s32 time;           /* 0x70 */
    s32 duration;       /* 0x74 */
    s32 ratio;          /* 0x78 */
    u8 pad7c[0x10];
    u16 frame;          /* 0x8c */
    u8 frameTimer;      /* 0x8e */
    u8 frameChanged;    /* 0x8f */
    Item *next;         /* 0x90 */
    Item *prev;         /* 0x94 */
};

struct Node {
    Item *item;
    Node *next;
    Node *prev;
};

struct Emitter {
    u8 pad000[0x4c];
    void *slots[6];     /* 0x4c */
    u8 pad064[4];
    u8 f068[0x30c];     /* 0x68 */
    s32 count;          /* 0x374 */
    Node *head;         /* 0x378 */
    Node *tail;         /* 0x37c */
    Node *freeList;     /* 0x380 */
    u8 pad384[0xc];
    u16 frameCount;     /* 0x390 */
    u8 pad392[2];
    u8 frameDelay;      /* 0x394 */
    u8 animate;         /* 0x395 */
    u8 loop;            /* 0x396 */
};

extern "C" {
void func_020bdfcc(void *a, void *b, Step dt);
void FX_DivAsync(s32 numer, s32 denom);
s32 func_020c930c(void);
void func_020c099c(void **arg0);

struct ItemPool {
    u8 pad000[0x5a0];
    s32 count;          /* 0x5a0 */
    Item *head;         /* 0x5a4 */
    Item *f5a8;         /* 0x5a8 */
    Item *free;         /* 0x5ac */
};
extern ItemPool data_021111ec;
extern Item *data_02111790;
extern Item *data_02111798;
extern s32 data_0211178c; // FAKE: same word as data_021111ec.count; the loop-site decrement uses the folded address, the final
                          // one base+0x5a0
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline bool vec_ne(const Vec3 &a, const Vec3 &b) {
    if (!(a.x == b.x && a.y == b.y && a.z == b.z)) {
        return true;
    }
    return false;
}

static inline void item_set_pos(Item *it, const Vec3 &p) {
    if (vec_ne(it->pos, p)) {
        vec_set(&it->pos, &p);
        it->dirty = 1;
    }
}

static inline void res_release(Res *res) {
    if (--res->refs == 0 && res->locked == 0) {
        res->release();
    }
    if (res->refs == 0 && res->refs2 == 0) {
        func_020c099c((void **) res);
    }
}

static inline void node_release(Emitter *self, Node *n) {
    if (n->prev != 0) {
        n->prev->next = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if (n == self->head) {
        self->head = n->next;
    }
    n->next        = self->freeList;
    self->freeList = n;
    self->count--;
}

enum {
    EMITTER_SLOTS = 6,
};

enum {
    FX32_ONE = 0x1000,
};

/*
 * Advances an emitter by one step (dt, fx32). Steps the leading non-null
 * entries of the six-slot array through func_020bdfcc, then walks the live
 * node list: each node's item gains dt of elapsed time. An expired item is
 * released (owner cleared, Res reference dropped, item returned to the
 * global item free list, node recycled); expiry of the first node is
 * deferred to the end of the walk. A live item gets its progress ratio
 * through FX_DivAsync/func_020c930c and moves by its velocity (scaled by dt
 * unless dt is exactly one), advancing its animation frame when enabled.
 */
extern "C" void func_020bc568(Emitter *self, Step dt) {
    s32 i;
    bool removeFirst;
    Node *node;
    Item *it;
    Res *r;
    Node *m;
    Item *e;
    Item **pf; // FAKE: free/live list heads held in locals at the final removal only; direct access or an inline helper
               // colours the address temps differently
    Item **ph;

    for (i = 0; i < EMITTER_SLOTS; i++) {
        if (self->slots[i] == 0) {
            break;
        }
        func_020bdfcc(self->slots[i], self->f068, dt);
    }
    removeFirst = false;
    node        = self->count != 0 ? self->head : self->tail;
    while (node != self->tail) {
        it = node->item;
        it->time += dt.v;
        if (it->time >= it->duration) {
            if (node == (self->count != 0 ? self->head : self->tail)) {
                removeFirst = true;
            } else {
                node           = node->prev;
                m              = node->next;
                m->item->owner = 0;
                r              = m->item->res;
                res_release(r);
                e = m->item;
                if (e->prev != 0) {
                    e->prev->next = e->next;
                }
                if (e->next != 0) {
                    e->next->prev = e->prev;
                }
                if (e == data_02111790) {
                    data_02111790 = e->next;
                }
                e->next       = data_02111798;
                data_02111798 = e;
                data_0211178c--;
                node_release(self, m);
            }
        } else {
            FX_DivAsync(it->time, it->duration);
            if (dt.v == FX32_ONE) {
                Vec3 p;
                const Vec3 &cp = it->pos;
                p.z            = it->pos.z + it->vel.z;
                p.y            = it->pos.y + it->vel.y;
                p.x            = cp.x + it->vel.x;
                item_set_pos(it, p);
                if (self->animate) {
                    if (--it->frameTimer == 0xff) {
                        it->frame++;
                        if (it->frame >= self->frameCount) {
                            it->frame = self->loop ? 0 : self->frameCount - 1;
                        }
                        it->frameTimer   = self->frameDelay;
                        it->frameChanged = 1;
                    }
                }
            } else {
                const Vec3 &cq = it->pos;
                Vec3 q;
                s32 dz = fx_mul(it->vel.z, dt.v);
                s32 dy = fx_mul(it->vel.y, dt.v);
                s32 dx = fx_mul(it->vel.x, dt.v);
                q.z    = it->pos.z;
                q.y    = it->pos.y;
                q.x    = cq.x;
                q.z += dz;
                q.y += dy;
                q.x += dx;
                item_set_pos(it, q);
            }
            it->ratio = func_020c930c();
        }
        node = node->next;
    }
    if (removeFirst) {
        m              = self->count != 0 ? self->head : self->tail;
        m->item->owner = 0;
        r              = m->item->res;
        res_release(r);
        e = m->item;
        if (e->prev != 0) {
            e->prev->next = e->next;
        }
        if (e->next != 0) {
            e->next->prev = e->prev;
        }
        pf = &data_02111798;
        ph = &data_02111790;
        if (e == *ph) {
            *ph = e->next;
        }
        e->next = *pf;
        *pf     = e;
        data_021111ec.count--;
        node_release(self, m);
    }
}
