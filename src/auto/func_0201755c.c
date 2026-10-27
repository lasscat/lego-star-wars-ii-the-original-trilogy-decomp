/* Reconstructed from USA ARM9 at 0x0201755c (676 bytes).
 * Runs two passes over a copy of the self position (the second pass shifts x
 * by 0xf000). For self types 0x103, 0x104 and 0x105 it spawns a companion
 * entity (kinds 0x104, 0x106, 0x107) from a transform built at that position,
 * then moves the companion to the position and flags it if it differed.
 */
#include "m2c.h"

enum {
    SELF_TYPE_A  = 0x103,
    SELF_TYPE_B  = 0x104,
    SELF_TYPE_C  = 0x105,
    COMPANION_A  = 0x104,
    COMPANION_B  = 0x106,
    COMPANION_C  = 0x107,
    PASS_X_SHIFT = 0xf000,
};

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 pre[0xb0];
    Vec pos;
    u8 mid[0x15];
    u8 f1;
} Obj;

typedef struct {
    u8 pre[0xb0];
    Vec pos;
    u8 m1[0xe];
    u16 w1;
    u8 m2[0x146];
    u16 type;
} Ent;

extern void func_020accac(void *, void *, void *, void *);
extern Obj *func_02015138(u32, u32, void *);

static inline int vec_ne(const Vec *a, const Vec *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec *d, const Vec *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

void func_0201755c(Ent *self) {
    Vec pos;
    s32 v[3];
    int i;

    pos.x = self->pos.x;
    pos.y = self->pos.y;
    pos.z = self->pos.z;
    for (i = 0; i < 2; i++) {
        u16 type;
        if (i != 0) {
            pos.x += PASS_X_SHIFT;
        }
        type = self->type;
        if (type == SELF_TYPE_A) {
            u16 p[4];
            u8 t[0x48];
            Obj *obj;
            if (i != 0) {
                pos.x += PASS_X_SHIFT;
            }
            v[0] = 0x1000;
            v[1] = 0x1000;
            v[2] = 0x1000;
            p[0] = 0;
            p[1] = self->w1;
            p[2] = 0;
            func_020accac(t, &pos, p, v);
            obj = func_02015138(COMPANION_A, 0, t);
            if (vec_ne(&obj->pos, &pos)) {
                vec_set(&obj->pos, &pos);
                obj->f1 = 1;
            }
        } else if (type == SELF_TYPE_C) {
            u16 p[4];
            u8 t[0x48];
            Obj *obj;
            v[0] = 0x1000;
            v[1] = 0x1000;
            v[2] = 0x1000;
            p[0] = 0;
            p[1] = self->w1;
            p[2] = 0;
            func_020accac(t, &pos, p, v);
            obj = func_02015138(COMPANION_C, 0, t);
            if (vec_ne(&obj->pos, &pos)) {
                vec_set(&obj->pos, &pos);
                obj->f1 = 1;
            }
        } else if (type == SELF_TYPE_B) {
            u16 p[4];
            u8 t[0x48];
            Obj *obj;
            v[0] = 0x1000;
            v[1] = 0x1000;
            v[2] = 0x1000;
            p[0] = 0;
            p[1] = self->w1;
            p[2] = 0;
            func_020accac(t, &pos, p, v);
            obj = func_02015138(COMPANION_B, 0, t);
            if (vec_ne(&obj->pos, &pos)) {
                vec_set(&obj->pos, &pos);
                obj->f1 = 1;
            }
        }
    }
}
