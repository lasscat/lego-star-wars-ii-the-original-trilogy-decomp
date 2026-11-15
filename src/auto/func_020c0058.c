/* Reconstructed from USA ARM9 at 0x020c0058 (428 bytes).
 *
 * Circular motion step for the 16-byte entry data_0210ecf4[arg1->0x4C].  The u16 angle at
 * entry +0 selects a pair from the s16 table data_020f88c4 (index angle >> 4: even element
 * = sine, odd element = cosine).  arg0->0x28 picks the plane: 0 replaces y/z, 1 replaces
 * x/z, 2 replaces x/y of the default offset data_020ff9b4 with cosine/sine times the fx32
 * radius at entry +8.  The angle then advances by the halfword at arg0->0x24 and the radius
 * by the step at entry +0xC.  arg1->0x24 plus the offset is stored back to arg1+0x24 (and
 * the byte at arg1+0x45 set) only when it differs from the current value.
 * The three halfword stack temporaries are the Angle wrapper copies: add_angle's result,
 * the by-value parameter of set_angle and the by-value increment.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u16 value;
} Angle;

typedef struct {
    Angle angle, unknown_halfword;
    s32 unknown, radius, step;
} Motion;

extern Motion data_0210ecf4[];
extern const s16 data_020f88c4[];
extern Vec3 data_020ff9b4;

enum {
    FX32_SHIFT = 0xc,
    FX32_HALF  = 0x800
};

static inline s32 mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX32_HALF) >> FX32_SHIFT);
}

static inline Angle add_angle(s32 a, Angle b) {
    Angle result;
    result.value = a + b.value;
    return result;
}

static inline void set_angle(Angle *d, Angle v) {
    d->value = v.value;
}

static inline int different(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void set(Vec3 *a, const Vec3 *b) {
    if (a != b) {
        a->x = b->x;
        a->y = b->y;
        a->z = b->z;
    }
}

void func_020c0058(void *arg0, void *arg1) {
    u32 index           = M2C_FIELD(arg1, u32 *, 0x4c);
    u8 *base            = (u8 *) data_0210ecf4;
    Motion *motion      = (Motion *) (base + (index << 4));
    s32 angle           = *(u16 *) (base + (index << 4));
    s32 axis            = M2C_FIELD(arg0, s32 *, 0x28);
    const Vec3 *initial = &data_020ff9b4;
    s32 slot            = angle >> 4;
    s32 even            = slot * 2;
    s32 odd             = even + 1;
    const s16 *table    = data_020f88c4;
    s32 x               = initial->x;
    s32 y               = initial->y;
    s32 z               = initial->z;
    s32 cosine          = *(s16 *) ((u8 *) table + (odd * 2));
    s32 sine            = *(s16 *) ((u8 *) table + (even * 2));
    Vec3 position;

    switch (axis) {
        case 0:
            y = mul(cosine, motion->radius);
            z = mul(sine, motion->radius);
            break;
        case 1:
            x = mul(cosine, motion->radius);
            z = mul(sine, motion->radius);
            break;
        case 2:
            x = mul(cosine, motion->radius);
            y = mul(sine, motion->radius);
            break;
    }
    {
        Angle inc  = M2C_FIELD(arg0, Angle *, 0x24);
        Angle next = add_angle(angle, inc);
        set_angle(&motion->angle, next);
    }
    motion->radius += motion->step;
    {
        s32 pz     = M2C_FIELD(arg1, s32 *, 0x2c) + z;
        s32 py     = M2C_FIELD(arg1, s32 *, 0x28) + y;
        s32 px     = M2C_FIELD(arg1, s32 *, 0x24) + x;
        position.x = px;
        position.y = py;
        position.z = pz;
    }
    if (!different((Vec3 *) ((u8 *) arg1 + 0x24), &position)) {
        return;
    }
    set((Vec3 *) ((u8 *) arg1 + 0x24), &position);
    M2C_FIELD(arg1, u8 *, 0x45) = 1;
}
