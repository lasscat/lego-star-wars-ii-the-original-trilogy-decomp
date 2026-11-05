#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} VecFx;

typedef struct {
    u32 f0;
    Vec3 min;
    Vec3 max;
    u32 mask;
    u32 f20;
} Box;

typedef struct {
    Box boxes[1];
    u8 pad24[0x3c8 - 0x24];
    u32 count;
    u8 pad3cc[0x3d8 - 0x3cc];
    u32 masks[4];
    u8 pad3e8[0x478 - 0x3e8];
    u8 masks_changed;
    u8 pad479;
    u8 f47a;
} World;

typedef struct {
    u8 pad0[0x4];
    Vec3 pos;
    u8 pad10[0x1c - 0x10];
    u8 kind;
    u8 pad1d[0x2c - 0x1d];
    s32 f2c;
} Thing;

typedef struct ListNode {
    Thing *obj;
    struct ListNode *next;
} ListNode;

typedef struct {
    u16 keys;
} Pad;

typedef struct Entity {
    u8 pad0[0x8];
    u32 flags;
    u8 padc[0x60 - 0xc];
    void *f60;
    void *f64;
    void *f68;
    u8 pad6c[0xb0 - 0x6c];
    Vec3 pos;
    u8 padbc[0xca - 0xbc];
    Angle yaw;
    u8 padcc[0xd0 - 0xcc];
    u8 yaw_dirty;
    u8 pos_dirty;
    u8 padd2[0x5ce - 0xd2];
    Pad pad;
    u8 pad5d0[0x5da - 0x5d0];
    u8 player;
    u8 pad5db[0x6bb - 0x5db];
    u8 f6bb;
    u8 pad6bc[0x814 - 0x6bc];
    struct Entity *f814;
    struct Entity *f818;
    s32 f81c;
    void *f820;
    u8 pad824[4];
    void *f828;
    u8 pad82c[4];
    s32 f830;
} Entity;

typedef struct {
    u8 pad0[4];
    ListNode *head;
    u8 pad8[0x4c - 0x8];
    Entity *f4c;
    Entity *f50;
    u8 pad54[0x68 - 0x54];
    World *world;
} Game;

typedef struct {
    u8 pad0[0x2a];
    u8 f2a;
} Cfg;

enum {
    /* d-pad bits of Pad.keys (KEY_UP = 0x40 as in func_020696f0, which reads the same
       input object data_021027f8) */
    KEY_RIGHT = 0x10,
    KEY_LEFT  = 0x20,
    KEY_UP    = 0x40,
    KEY_DOWN  = 0x80,
};

enum {
    /* 16-bit direction angle (0x10000 = full turn) chosen for each d-pad combination;
       each diagonal is the midpoint of its two cardinal directions */
    DIR_DOWN       = 0,
    DIR_DOWN_RIGHT = 0x2000,
    DIR_RIGHT      = 0x4000,
    DIR_UP_RIGHT   = 0x6000,
    DIR_UP         = 0x8000,
    DIR_UP_LEFT    = 0xa000,
    DIR_LEFT       = 0xc000,
    DIR_DOWN_LEFT  = 0xe000,
};

extern Game data_0210930c;
extern Cfg data_021027f8;
extern M2C_UNK data_02104dc4;

void func_0200e4ec(Entity *);
void func_0200ee24(Entity *);
void func_0204a620(Pad *);
u16 func_0205d140(Cfg *, s32);
void func_02059e64(Pad *, s32);
void func_0204a5f8(Pad *, Angle *);
void func_02004034(Entity *, Fx);
s16 func_020985d8(s32, s32);
s32 func_0208c6ac(void *, s32, s32);
void func_020b9584(s32, Vec3 *);
void func_01ff8abc(Entity *, u32);
void func_0200f274(Entity *);
s32 func_0200f5d0(Vec3 *, Vec3 *, Fx, s32 *);

static inline s32 box_contains(const Box *b, const Vec3 *p, s32 x) {
    if (x < b->min.x || x > b->max.x || p->z < b->min.z || p->z > b->max.z || p->y < b->min.y || p->y > b->max.y) {
        return 0;
    }
    return 1;
}

static inline s32 vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void set_pos(Entity *e, const Vec3 *p) {
    if (vec_ne(&e->pos, p)) {
        vec_set(&e->pos, p);
        e->pos_dirty = 1;
    }
}

static inline void set_pos_y(Entity *e, Fx y) {
    if (e->pos.y != y.v) {
        e->pos.y     = y.v;
        e->pos_dirty = 1;
    }
}

static inline void set_yaw_inner(Entity *e, Angle a) {
    if (e->yaw.v != a.v) {
        e->yaw       = a;
        e->yaw_dirty = 1;
    }
}

static inline Angle angle(u16 v) {
    Angle a;
    a.v = v;
    return a;
}

static inline void angle_set(Angle *d, Angle s) {
    d->v = s.v;
}

static inline Angle angle_ptr(Angle *s) {
    Angle a;
    a = *s;
    return a;
}

static inline Angle *angle_init(Angle *d, u16 v) {
    d->v = v;
    return d;
}

static inline void set_yaw_value(Entity **slot, u16 v) {
    Angle a;
    a.v = v;
    set_yaw_inner(*slot, angle_ptr(&a));
}

static inline void set_dir(Angle *d, u16 v) {
    Angle a;
    a.v = v;
    angle_set(d, angle_ptr(&a));
}

/* The target stores each nonzero d-pad angle to a temp at both inline levels
   (sp+0x2a..0x1c, then sp+0x14..0x06) with no reload in between; only the
   DOWN site (value 0, shared with the cleared dir) reloads its temp, so it
   keeps the copy-through-temp form set_dir above. */
static inline u16 angle_keep(Angle *k, u16 v) {
    Angle b;
    *(u16 *) k  = v;
    *(u16 *) &b = v;
    return v;
}

static inline void set_dir_k2(Angle *d, u16 v) {
    Angle k;
    d->v = angle_keep(&k, v);
}

static inline void vec_sub(VecFx *r, const Vec3 *a, const Vec3 *b) {
    s32 z = a->z;
    s32 y = a->y;
    s32 x;
    z -= b->z;
    y -= b->y;
    x      = a->x - b->x;
    r->x.v = x;
    r->y.v = y;
    r->z.v = z;
}

static inline u16 fx_atan2(Fx x, Fx z) {
    return func_020985d8(x.v, z.v);
}

static inline u16 angle_to(const Vec3 *from, const Vec3 *to) {
    VecFx d;
    Fx qx;
    Fx qz;
    Angle a;
    vec_sub(&d, to, from);
    qz  = d.z;
    qx  = d.x;
    a.v = fx_atan2(qx, qz);
    return a.v;
}

static inline Entity *entity_of(void *p) {
    if (p != 0) {
        p = (u8 *) p - 4;
    }
    return (Entity *) p;
}

void func_0200dafc(Entity *self, Fx arg, ...) {
    Vec3 pos;
    Angle dir;
    s32 changed;
    u16 keys;

    func_0200e4ec(self);

    if (self->f60 != 0 || self->f64 != 0 || self->f68 != 0) {
        u32 i;
        u32 mask;
        World *w;
        u8 player;
        Box *b;
        s32 x;
        u32 n;
        w      = data_0210930c.world;
        mask   = 0;
        i      = 0;
        n      = w->count;
        player = self->player;
        if (i < n) {
            x = self->pos.x;
            b = w->boxes;
            do {
                if (box_contains(b, &self->pos, x)) {
                    mask |= b->mask;
                }
                i++;
                b++;
            } while (i < n);
        }
        if (mask != w->masks[player] && mask != 0) {
            w->masks_changed = 1;
            w->masks[player] = mask;
        }
    }

    if (self->f830 != 0) {
        if (--self->f830 == 0) {
            func_0200ee24(self);
        } else {
            Entity *e;
            pos.x = self->pos.x;
            pos.z = self->pos.z;
            pos.y = self->pos.y + 0xc000;
            e     = (Entity *) self->f820;
            if (e != 0) {
                e = (Entity *) ((u8 *) e - 4);
            }
            set_pos(e, &pos);
            e = (Entity *) self->f828;
            if (e != 0) {
                e = (Entity *) ((u8 *) e - 4);
            }
            set_pos(e, &pos);
        }
    }

    /* func_0204a620 clears pad+0xd; func_0204a5f8 sets it and stores *dir at pad+0xe */
    func_0204a620(&self->pad);
    func_02059e64(&self->pad, func_0205d140(&data_021027f8, self->player));

    changed = 0;
    dir.v   = 0;
    keys    = self->pad.keys;
    if (keys & KEY_UP) {
        if (keys & KEY_LEFT) {
            set_dir_k2(&dir, DIR_UP_LEFT);
        } else if (keys & KEY_RIGHT) {
            set_dir_k2(&dir, DIR_UP_RIGHT);
        } else {
            set_dir_k2(&dir, DIR_UP);
        }
        changed = 1;
    } else if (keys & KEY_DOWN) {
        if (keys & KEY_LEFT) {
            set_dir_k2(&dir, DIR_DOWN_LEFT);
        } else if (keys & KEY_RIGHT) {
            set_dir_k2(&dir, DIR_DOWN_RIGHT);
        } else {
            set_dir(&dir, DIR_DOWN);
        }
        changed = 1;
    } else if (keys & KEY_LEFT) {
        set_dir_k2(&dir, DIR_LEFT);
        changed = 1;
    } else if (keys & KEY_RIGHT) {
        set_dir_k2(&dir, DIR_RIGHT);
        changed = 1;
    }
    if (changed) {
        func_0204a5f8(&self->pad, &dir);
    }

    func_02004034(self, arg);

    if (self->f814 != NULL) {
        Entity *t   = self->f814;
        Entity *ref = data_021027f8.f2a == 0 ? data_0210930c.f50 : data_0210930c.f4c;
        Vec3 *p     = &self->pos;
        set_pos(t, p);
        if (ref != NULL) {
            set_yaw_value(&self->f814, angle_to(&self->pos, &ref->pos));
        } else {
            set_yaw_value(&self->f814, 0);
        }
        set_pos_y(self->f814, *(Fx *) &self->pos.y);
    }

    if (self->f818 != NULL) {
        Entity *e;
        Fx radius;
        s32 dist;
        Thing *o;
        Thing *best;
        ListNode *node;
        s32 best_dist;
        Vec3 *p;

        if (self->f81c > 0) {
            self->f81c--;
        }
        e = self->f818;
        p = &self->pos;
        set_pos(e, p);

        best     = NULL;
        radius.v = best_dist = 0x7fffffff;
        dist                 = 0;
        node                 = data_0210930c.head;
        if (node != NULL) {
            do {
                o = node->obj;
                if (o->kind == 0xb && func_0208c6ac(&data_02104dc4, data_0210930c.world->f47a, o->f2c) == 0) {
                    dist = 0;
                    if (func_0200f5d0(&self->pos, &o->pos, radius, &dist) != 0) {
                        if (best == NULL || dist < best_dist) {
                            best_dist = dist;
                            best      = o;
                        }
                    }
                }
                node = node->next;
            } while (node != NULL);
        }
        if (best != NULL) {
            self->f818->flags |= 1;
            set_yaw_value(&self->f818, angle_to(&self->pos, &best->pos));
            if (self->f81c == 0) {
                func_020b9584(0x6a, &best->pos);
                self->f81c = 0x1e;
            }
        } else {
            self->f818->flags &= ~1;
        }
    }
    if ((self->flags & 0x802) == 0 && (self->flags & 1) == 1) {
        func_01ff8abc(self, 1);
        if (self->f6bb == 0x55) {
            func_0200f274(self);
        }
    }
}
