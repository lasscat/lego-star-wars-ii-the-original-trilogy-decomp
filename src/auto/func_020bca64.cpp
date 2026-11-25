/* func_020bca64 - spawns one particle for an emitter (names are inferred from use).
 *
 * 1. If the emitter's node list is full (0x40) its first node is recycled; else if the
 *    particle list is full the first particle's owner recycles one of its own nodes. Then
 *    nodes are recycled until the emitter is below its own limit.
 * 2. Takes a particle from the global free chain and a node from the emitter's free chain,
 *    links both in before their list tails and adds one reference to the emitter's RefObj.
 * 3. Initialises the particle: position (the emitter's, or data_020ff9b4 when either flag bit
 *    is set, plus the rotated Spec offset), the vector at +0x54, angles and scale, then calls
 *    the leading non-null entries of the six Cb pointers.
 * 4. Steps the Spec's three counters in up to three passes; a counter takes part in the pass
 *    given by its id, and the next pass only runs when a counter reached its limit.
 *
 * The particle list sits at data_0210e1ec+0x35a0, the object whose node list func_020bc190
 * and func_020bbaf8 use. data_021111ec (+0x3000), data_0211178c (+0x35a0), data_02111790,
 * data_02111794 and data_02111798 are addresses inside it.
 */
#include "m2c.h"

enum {
    FX_ONE      = 0x1000,
    POOL_SIZE   = 0x40, /* entries in the particle list and in an emitter's node list */
    CB_COUNT    = 6,
    SLOT_COUNT  = 3,
    PASS_COUNT  = 3,
    EMITTER_F10 = 0x10, /* either flag: start from data_020ff9b4 instead of the emitter */
    EMITTER_F29 = 0x20000000
};

/* Slot::flags */
enum {
    SLOT_BOUNCE  = 0x1,  /* at the limit: step back twice and flip SLOT_REVERSE */
    SLOT_HALF    = 0x2,  /* at the limit: restart from max / 2 */
    SLOT_MIRROR  = 0x8,  /* cur becomes max - 1 - cur on every call */
    SLOT_REVERSE = 0x10, /* count down instead of up */
    SLOT_ODD     = 0x20  /* toggled on every SLOT_MIRROR call; cur only steps when set */
};

extern "C" {
void func_020c099c(void **);
s32 func_02062ab4(s32, s32);
void MTX_Identity44_(void *);
void func_01ffa9e8(void *, void *);
}

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

struct Vec3 {
    s32 x, y, z;

    Vec3() {}
    Vec3(s32 ax, s32 ay, s32 az) {
        x = ax;
        y = ay;
        z = az;
    }
    Vec3(const Vec3 &o) {
        x = o.x;
        y = o.y;
        z = o.z;
    }
    Vec3 operator+(const Vec3 &o) const {
        return Vec3(x + o.x, y + o.y, z + o.z);
    }
    Vec3 &operator=(const Vec3 &o) {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
        return *this;
    }
    bool operator!=(const Vec3 &o) const {
        if (x != o.x || y != o.y || z != o.z) {
            return true;
        }
        return false;
    }
    Vec3 operator*(s32 s) const {
        s32 ty = y;
        s32 tz = z;
        s32 vz = FxMul(tz, s);
        s32 vy = FxMul(ty, s);
        s32 vx = FxMul(x, s);
        return Vec3(vx, vy, vz);
    }
};

extern "C" {
Vec3 func_01ffabe4(void *, const Vec3 &);
Vec3 func_0200ad80(const Vec3 &);
Vec3 func_020bd75c(void *);
}

struct Ang {
    u16 v;

    Ang get() const {
        return *this;
    }
};

struct Ang3 {
    Ang x, y, z;

    bool operator==(const Ang3 &o) const {
        return x.v == o.x.get().v && y.v == o.y.get().v && z.v == o.z.get().v;
    }
};

class RefObj {
public:
    virtual void unknown00();
    virtual void addRef();
    virtual void release();
    u8 pad04[8];
    s32 refs;
    s32 weak;
    u8 hold;
};

typedef struct Slot {
    s32 pad0;
    u8 max;
    u8 cur;
    u8 id;
    u8 flags;
} Slot;

class Spec {
public:
    virtual void unknown00();
    virtual Vec3 offset();
    u8 pad04[4];
    s32 f08;
    s32 f0c;
    u8 pad10[4];
    s32 speedA;
    s32 speedB;
    u8 pad1c[0x34 - 0x1c];
    s32 f34;
    s32 f38;
    s32 scaleA;
    s32 scaleB;
    u8 useDir;
    u8 pad45[3];
    Slot slots[SLOT_COUNT];
};

typedef struct Emitter Emitter;

typedef struct Particle {
    u8 pad00[0x24];
    Vec3 pos;
    Vec3 scale;
    Ang3 ang;
    u8 pad42[2];
    u8 angDirty;
    u8 dirty;
    u8 pad46[2];
    Emitter *owner;
    u8 pad4c[4];
    RefObj *obj;
    Vec3 vel;
    u8 pad60[0xc];
    s32 f6c;
    s32 f70;
    s32 f74;
    s32 f78;
    u8 pad7c[0x8c - 0x7c];
    s16 f8c;
    u8 f8e;
    u8 f8f;
    struct Particle *next;
    struct Particle *prev;
} Particle;

typedef struct Node {
    Particle *p;
    struct Node *next;
    struct Node *prev;
} Node;

class Cb {
public:
    virtual void apply(struct Particle *p);
};

struct Emitter {
    u8 pad00[0x24];
    Vec3 pos;
    u8 pad30[0x3c - 0x30];
    Ang3 ang;
    u8 pad42[0x48 - 0x42];
    Spec *spec;
    Cb *cbs[CB_COUNT];
    RefObj *obj;
    u8 pad68[0x374 - 0x68];
    s32 count;
    Node *head;
    Node *tail;
    Node *free;
    u32 flags;
    u8 pad388[4];
    s32 max;
    u16 f390;
    u8 pad392[2];
    u8 f394;
    u8 f395;
    u8 pad396;
    u8 f397;
};

typedef struct Pool {
    u8 pad[0x35a0];
    s32 count;
    Particle *head;
    Particle *tail;
    Particle *free;

    Particle *first() {
        return count != 0 ? head : tail;
    }
    void remove(Particle *p) {
        if (p->prev != 0) {
            p->prev->next = p->next;
        }
        if (p->next != 0) {
            p->next->prev = p->prev;
        }
        if (p == head) {
            head = p->next;
        }
        p->next = free;
        free    = p;
        count -= 1;
    }
} Pool;

extern "C" {
extern Pool data_0210e1ec;
extern Vec3 data_020ff9b4;
}

static inline void obj_release(RefObj *o) {
    o->refs -= 1;
    if (o->refs == 0 && o->hold == 0) {
        o->release();
    }
    if (o->refs == 0 && o->weak == 0) {
        func_020c099c((void **) o);
    }
}

static inline void node_unlink(Emitter *e, Node *n) {
    if (n->prev != 0) {
        n->prev->next = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    if (n == e->head) {
        e->head = n->next;
    }
    n->next = e->free;
    e->free = n;
    e->count -= 1;
}

static inline void obj_acquire(RefObj *o) {
    if (o->refs == 0 && o->hold == 0) {
        o->addRef();
    }
    o->refs += 1;
}

/* Frees the emitter's first node: clears its particle's owner, drops one RefObj reference
 * and returns the particle and the node to their free chains. */
static inline void recycle(Emitter *e) {
    Node *n     = e->count != 0 ? e->head : e->tail;
    n->p->owner = 0;
    obj_release(n->p->obj);
    data_0210e1ec.remove(n->p);
    node_unlink(e, n);
}

/* Advances one counter; returns 1 when it reached its limit, else 0. */
static inline s32 slot_step(Slot *s, s32 pass) {
    s32 step, limit, done;

    if (s->max == 0 || s->id != pass) {
        return 0;
    }
    done = 0;
    if (s->flags & SLOT_REVERSE) {
        step  = -1;
        limit = 0xff;
    } else {
        step  = 1;
        limit = s->max;
    }
    if (s->flags & SLOT_MIRROR) {
        s->cur = s->max - 1 - s->cur;
        if (s->flags & SLOT_ODD) {
            s->cur += step;
            done = s->cur == limit;
        }
        s->flags ^= SLOT_ODD;
    } else {
        s->cur += step;
        done = s->cur == limit;
    }
    if (done) {
        if (s->flags & SLOT_BOUNCE) {
            s->cur += step * -2;
            s->flags ^= SLOT_REVERSE;
        } else if (s->flags & SLOT_HALF) {
            s->cur = s->max >> 1;
        } else if (s->flags & SLOT_REVERSE) {
            s->cur = s->max - 1;
        } else {
            s->cur = 0;
        }
        return 1;
    }
    return 0;
}

static inline const Vec3 &emitter_pos(const Emitter *e) {
    return e->pos;
}

static inline void set_pos(Particle *p, const Vec3 &val) {
    if (p->pos != val) {
        p->pos   = val;
        p->dirty = 1;
    }
}

static inline void set_scale(Particle *p, const Vec3 &val) {
    if (p->scale != val) {
        p->scale = val;
        p->dirty = 1;
    }
}

static inline void set_ang(Particle *p, const Ang3 &val) {
    if (!(val == p->ang)) {
        p->ang.x    = val.x.get();
        p->ang.y    = val.y.get();
        p->ang.z    = val.z.get();
        p->angDirty = 1;
    }
}

extern "C" void func_020bca64(Emitter *e) {
    Particle *np;

    if (e->count == POOL_SIZE) {
        recycle(e);
    } else if (data_0210e1ec.count == POOL_SIZE) {
        recycle(data_0210e1ec.first()->owner);
    }
    while (e->count >= e->max) {
        recycle(e);
    }

    np                 = data_0210e1ec.free;
    Particle *pat      = data_0210e1ec.tail;
    data_0210e1ec.free = np->next;
    if (pat->prev != 0) {
        pat->prev->next = np;
    }
    np->prev  = pat->prev;
    np->next  = pat;
    pat->prev = np;
    if (pat == data_0210e1ec.head || data_0210e1ec.count == 0) {
        np->prev           = data_0210e1ec.tail;
        data_0210e1ec.head = np;
    }
    data_0210e1ec.count += 1;

    Node *nn = e->free;
    Node *at = e->tail;
    e->free  = nn->next;
    if (at->prev != 0) {
        at->prev->next = nn;
    }
    nn->prev = at->prev;
    nn->next = at;
    at->prev = nn;
    if (at == e->head || e->count == 0) {
        nn->prev = e->tail;
        e->head  = nn;
    }
    e->count += 1;
    nn->p = np;

    np->owner = e;
    np->obj   = e->obj;
    np->f70   = 0;
    np->f78   = 0;
    np->f6c   = FX_ONE;
    obj_acquire(e->obj);

    if (e->f395 != 0) {
        if (e->f397 == 0) {
            np->f8c = 0;
        } else {
            np->f8c = func_02062ab4(0, e->f390 - 1);
        }
        np->f8e = e->f394;
        np->f8f = 1;
    }

    Vec3 pos;
    pos.x  = 0;
    pos.y  = 0;
    pos.z  = 0;
    Vec3 v = e->spec->offset();
    s32 mtx[16];
    MTX_Identity44_(mtx);
    if ((e->flags & EMITTER_F29) || (e->flags & EMITTER_F10)) {
        pos = data_020ff9b4;
        func_01ffa9e8(mtx, &e->ang);
    } else {
        pos = emitter_pos(e);
        func_01ffa9e8(mtx, &e->ang);
    }
    v = func_01ffabe4(mtx, v);

    set_pos(np, pos + v);

    Spec *spec = e->spec;
    if (spec->useDir != 0) {
        s32 s = func_02062ab4(spec->speedA, spec->speedB);
        if (v != data_020ff9b4) {
            np->vel = func_0200ad80(v) * s;
        } else {
            np->vel = func_01ffabe4(mtx, Vec3(0, FX_ONE, 0)) * s;
        }
    } else {
        np->vel = func_01ffabe4(mtx, func_020bd75c((u8 *) spec + 0x14));
    }

    set_ang(np, e->ang);

    np->f74 = func_02062ab4(e->spec->f08, e->spec->f0c) << 12;
    np->f6c = func_02062ab4(e->spec->f34, e->spec->f38);
    s32 s   = func_02062ab4(e->spec->scaleA, e->spec->scaleB);
    set_scale(np, Vec3(s, s, s));

    for (s32 i = 0; i < CB_COUNT; i++) {
        Cb *cb = e->cbs[i];
        if (cb == 0) {
            break;
        }
        cb->apply(np);
    }

    for (s32 pass = 0; pass < PASS_COUNT; pass++) {
        bool any = false;
        for (s32 j = 0; j < SLOT_COUNT; j++) {
            any |= slot_step(&e->spec->slots[j], pass);
        }
        if (!any) {
            return;
        }
    }
}
