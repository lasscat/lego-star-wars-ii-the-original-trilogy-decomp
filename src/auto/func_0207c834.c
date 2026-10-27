#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Half;

typedef struct {
    Half x;
    Half y;
    Half z;
} Rot3;

typedef struct {
    s32 v;
} UnkVal;

/* The object returned by func_020aaeb4 (&data_02109c88); only the fields used here. */
typedef struct {
    u8 pad0[0x28];
    Vec3 pos; /* s32 triple; func_020a0630 copies it to +0x34c */
    u8 pad1[0x40 - 0x34];
    Rot3 rot; /* u16 triple; func_020a0630 copies it to +0x358 */
    u8 f46[2];
    u8 rot_changed; /* set to 1 when rot is given a different value */
    u8 pos_changed; /* set to 1 when pos is given a different value */
    u8 pad2[0x1ac - 0x4a];
    u32 f1ac;
    u8 f1b0;
} Obj;

enum {
    NEW_POS_Y    = 0x9000,
    NEW_POS_Z    = 0x1e000,
    NEW_ROT_X    = 0xfdde, /* -0x222 as a signed halfword */
    F1AC_FLAG    = 0x4,
    FORWARD_WORD = 0x1000, /* passed on to func_020a0630, which does not read it */
    UPDATE_INDEX = 0x0,
};

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

/* Copy s into d with the component order reversed. */
static inline void rot_swz(Rot3 *d, const Rot3 *s) {
    d->x = s->z;
    d->y = s->y;
    d->z = s->x;
}

static inline int half_eq(u16 a, Half b) {
    return a == b.v;
}

static inline int rot_eq(const Rot3 *a, const Rot3 *b) {
    return half_eq(a->x.v, b->x) && half_eq(a->y.v, b->y) && half_eq(a->z.v, b->z);
}

static inline void half_set(Half *d, Half s) {
    d->v = s.v;
}

static inline void rot_set(Rot3 *d, const Rot3 *s) {
    half_set(&d->x, s->x);
    half_set(&d->y, s->y);
    half_set(&d->z, s->z);
}

Obj *func_020aaeb4(void);
void func_020a0440(Obj *, UnkVal, u8);

/* Entry 3 of the function table data_020ff1a4. Put the shared object returned by
 * func_020aaeb4 into a fixed state and run its update for index 0; func_0207d394
 * uses the same pos/rot sequence and helpers with a different update index.
 *
 * - Clear the byte at +0x1b0 and set bit 0x4 of the word at +0x1ac (roles unknown).
 * - Store pos = {0, 0x9000, 0x1e000} and rot = {0xfdde, 0, 0}. Each triple is
 *   written, and its changed flag set, only when it differs from the stored one.
 * - func_020a0440(obj, word, 0) runs func_020a0630, which copies pos and rot into
 *   the record at +0x300 and selects its update path from the byte at +0x208 + 0
 *   (the word is not read there), then calls func_020a9158 and increments the
 *   counter at +0x200.
 *
 * Every step fetches the object again through func_020aaeb4.
 */
void func_0207c834(void) {
    Vec3 new_pos;
    Vec3 *pos_src;
    UnkVal word;
    Rot3 new_rot;
    Rot3 rot_rev;
    Rot3 rot_rev_copy;
    Rot3 *rot_src;
    Obj *o;

    o       = func_020aaeb4();
    o->f1b0 = 0;
    o->f1ac |= F1AC_FLAG;

    new_pos.x = 0;
    new_pos.y = NEW_POS_Y;
    new_pos.z = NEW_POS_Z;
    pos_src   = &new_pos;
    o         = func_020aaeb4();
    if (vec_ne(&o->pos, pos_src)) {
        vec_set(&o->pos, pos_src);
        o->pos_changed = 1;
    }

    /* The rot triple is built in reversed component order, then reversed into place. */
    rot_rev.x.v  = 0;
    rot_rev.y.v  = 0;
    rot_rev.z.v  = NEW_ROT_X;
    rot_rev_copy = rot_rev;
    o            = func_020aaeb4();
    rot_src      = &new_rot;
    rot_swz(rot_src, &rot_rev_copy);
    if (!rot_eq(rot_src, &o->rot)) {
        rot_set(&o->rot, rot_src);
        o->rot_changed = 1;
    }

    word.v = FORWARD_WORD;
    func_020a0440(func_020aaeb4(), word, UPDATE_INDEX);
}
