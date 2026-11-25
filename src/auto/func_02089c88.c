/* func_02089c88: first passes each of the eight 8-byte buffers of the argument (+0x2a28) to
 * func_02090858(data_0210930c.f_68, index, buffer), then calls func_02089e60(arg). Then walks the
 * four entity slots of data_0210930c (+0x4c); for each non-NULL slot whose 64-byte source record
 * (array at +0x21c0) has mode (+0x24) != MODE_SENTINEL:
 * - the record position (+0x0) is copied to the entity (+0xb0) when it differs (dirty flag +0xd1);
 * - the record's three u16 angles (+0x1c) are copied to the entity (+0xc8) when any differs
 *   (dirty flag +0xd0);
 * - the record's second vector (+0xc) is copied to the entity (+0x6a0).
 */
#include "m2c.h"

enum {
    BUF_COUNT     = 8,
    SLOT_COUNT    = 4,
    MODE_SENTINEL = 100,
};

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
    u8 padbc[0xc8 - 0xbc];
    HalfVal yaw[3];
    u8 padce[2];
    u8 f_d0;
    u8 f_d1;
    u8 padd2[0x6a0 - 0xd2];
    Vec3 pos2;
} Ent;

typedef struct {
    u8 pad0[0x4c];
    Ent *slots[4];
    u8 pad5c[0x68 - 0x5c];
    s32 f_68;
} Globals;

typedef struct {
    Vec3 pos;
    Vec3 pos2;
    u8 pad18[0x1c - 0x18];
    HalfVal ang[3];
    u8 pad22[2];
    s16 mode;
    u8 pad26[0x40 - 0x26];
} Src;

typedef struct {
    u8 pad0[0x21c0];
    Src src[4];
    u8 pad22c0[0x2a28 - 0x22c0];
    u8 buf[8][8];
} Owner;

extern Globals data_0210930c;

void func_02090858(s32, s32, void *);
void func_02089e60(Owner *);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int half_eq(const HalfVal *a, HalfVal b) {
    return a->v == b.v;
}

static inline void put_half(HalfVal *d, HalfVal v) {
    d->v = v.v;
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void set_pos(Ent *e, const Vec3 *p) {
    if (vec_ne(&e->pos, p)) {
        vec_set(&e->pos, p);
        e->f_d1 = 1;
    }
}

static inline void sync_ang(Ent *o, Owner *s, u32 i) {
    int eq;
    int all;
    all = 0;
    eq  = 0;
    if (half_eq((const HalfVal *) ((u8 *) s + i * 64 + 0x21dc),
                o->yaw[0])) { // FAKE: raw spelling of &s->src[i].ang[0], as in func_020897f8
        if (half_eq(&s->src[i].ang[1], o->yaw[1])) {
            eq = 1;
        }
    }
    if (eq) {
        if (half_eq(&s->src[i].ang[2], o->yaw[2])) {
            all = 1;
        }
    }
    if (!all) {
        put_half(&o->yaw[0], *(const HalfVal *) ((u8 *) s + i * 64 + 0x21dc)); // FAKE: same raw spelling
        put_half(&o->yaw[1], s->src[i].ang[1]);
        put_half(&o->yaw[2], s->src[i].ang[2]);
        o->f_d0 = 1;
    }
}

void func_02089c88(Owner *self) {
    u8 i;
    Ent *e;
    Vec3 *s;
    s32 x;
    u32 j;
    int ne;

    for (i = 0; i < BUF_COUNT; i++) {
        func_02090858(data_0210930c.f_68, i, self->buf[i]);
    }
    func_02089e60(self);
    for (j = 0; j < SLOT_COUNT; j = (u8) (j + 1)) {
        e = data_0210930c.slots[j];
        if (e != NULL && self->src[j].mode != MODE_SENTINEL) {
            // FAKE: cast row spelling builds (self + j*64) + 0x21c0 so the row base is shared with the compares
            s = &((Owner *) ((u8 *) self + j * 0x40))->src[0].pos;
            x = s->x;
            if (e->pos.x != x || e->pos.y != self->src[j].pos.y || e->pos.z != self->src[j].pos.z) {
                ne = 1;
            } else {
                ne = 0;
            }
            if (ne) {
                if (&e->pos != s) {
                    e->pos.x = x;
                    e->pos.y = self->src[j].pos.y;
                    e->pos.z = self->src[j].pos.z;
                }
                e->f_d1 = 1;
            }
            sync_ang(e, self, j);
            s = &self->src[j].pos2;
            if (&e->pos2 != s) {
                e->pos2.x = s->x;
                e->pos2.y = self->src[j].pos2.y;
                e->pos2.z = self->src[j].pos2.z;
            }
        }
    }
}
