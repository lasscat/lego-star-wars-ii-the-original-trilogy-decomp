/* Puts an on-stack probe object (vtable data_020fcd18, then data_020fe4a8) at
 * arg1->pos + radius * (sin, 0, cos) of arg1->yaw, where radius = 0.3 * 10.0 = 3.0 (fx32, rounded FX_Mul)
 * and sin/cos come from the s16 pair table data_020f88c4 at index yaw >> 4. func_0204f760 gives it
 * range 10.0 and func_0204f53c fills its box; the lists that func_020555c4 yields for data_021094ac and
 * that box are walked, and every object other than arg1 whose shape passes func_01ff84bc(&o, shape)
 * adds its shape position to a sum. With no hits the function returns. Otherwise the sum is divided by
 * the hit count, func_0201807c gives the angle from arg1 to that point, and arg0->v becomes +0x71c or
 * -0x71c (about +/-10 degrees) by the sign of that angle minus arg1->yaw. With reach = 2 * 10.0 and
 * dist = max(reach - |point - arg1->pos|, 0) (64-bit hardware square root, rounded),
 * arg0->f4 = (dist^2 * (75.0 / reach^2) in fx32) >> 12, plus 25. What arg0, f4 and the probe
 * object are is not established here. */
#include "m2c.h"

typedef struct {
    u16 v;
} Ang;

typedef struct {
    Ang v;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} Key;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad0[0x20];
    void *shape;
} Ent;

typedef struct {
    u8 pad0[0x4];
    s32 x;
    s32 y;
    s32 z;
} Shape;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
    u8 padbc[0xca - 0xbc];
    Ang yaw;
} Target;

typedef struct {
    s32 v;
} Scalar;

typedef struct {
    void *vptr;
    Vec3 pos;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s16 h0;
    s16 h1;
    s16 h2;
    s32 w;
} Obj;

typedef struct {
    s32 v[6];
} Box;

typedef struct {
    s32 w[6];
} Iter;

typedef struct Link {
    Ent *obj;
    struct Link *next;
} Link;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe4a8;
extern M2C_UNK data_021094ac;
extern const s16 data_020f88c4[];

extern s32 func_01ff84bc(void *a, void *b);
extern void func_02007f24(s32 *out, double v);
extern void func_0200af88(u8 *arg0, s32 arg1);
extern void func_0201807c(Ang *out, Target *a, Vec3 *b, s32 flag);
extern void func_0202732c(void *arg0);
extern void func_0204f53c(void *arg0, void *arg1);
extern void func_0204f760(Obj *o, Scalar s);
extern void *func_020555c4(void *arg0, s32 arg1, void *arg2);
extern void func_02055630(void *arg0);
extern s32 func_02055660(const void *object);
extern s32 func_02055684(void *arg0);
extern s32 FX_Div(s32, s32);

enum {
    REG_SQRTCNT       = 0x040002b0,
    REG_SQRT_RESULT   = 0x040002b4,
    REG_SQRT_PARAM    = 0x040002b8,
    SQRT_MODE_64      = 1,
    MATH_BUSY         = 0x8000,
    FX_SHIFT          = 12,
    FX_HALF           = 0x800,
    ANGLE_INDEX_SHIFT = 4
};
enum {
    RANGE       = 0xa000,
    REACH_SCALE = 0x2000,
    TURN_POS    = 0x71c,
    TURN_NEG    = 0xf8e4,
    F4_SPAN     = 0x4b000,
    F4_BASE     = 0x19
};

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

static inline void vec_div_b(Vec3 *v, Scalar s) {
    {
        Scalar t = s;
        v->x     = FX_Div(v->x, t.v);
    }
    {
        Scalar t = s;
        v->y     = FX_Div(v->y, t.v);
    }
    {
        Scalar t = s;
        v->z     = FX_Div(v->z, t.v);
    }
}

static inline s16 ang_diff(u16 a, Ang b) {
    return (s16) (u16) (a - b.v);
}

static inline void key_turn3(Key *k, Ang a) {
    Ang t  = a;
    k->v.v = t.v;
}

void func_020278ac(Key *arg0, Target *arg1) {
    Scalar range;
    s32 scale;
    s32 radius;
    int x, y, z;
    Obj o;
    Box box;
    Vec3 sum;
    Iter it;
    s32 count;
    Link *n;
    Scalar div;
    Ang ang;
    s32 reach;
    s32 dist;
    s64 dist_sq;
    s32 *zp;

    range.v = RANGE;
    func_0202732c(arg0);
    func_02007f24(&scale, 0.3);
    radius  = fx_mul(scale, range.v);
    x       = fx_mul(radius, data_020f88c4[(arg1->yaw.v >> ANGLE_INDEX_SHIFT) * 2]);
    z       = fx_mul(radius, data_020f88c4[(arg1->yaw.v >> ANGLE_INDEX_SHIFT) * 2 + 1]);
    z       = arg1->pos.z + z;
    y       = arg1->pos.y;
    x       = arg1->pos.x + x;
    o.vptr  = &data_020fcd18;
    o.pos.x = x;
    o.pos.y = y;
    o.pos.z = z;
    o.f10   = 0;
    o.a0    = 0;
    o.a1    = 0;
    o.a2    = 0;
    o.sum   = 0;
    func_0200af88(&o.f24[0], o.sum - 1);
    o.f24[2] = 0;
    o.vptr   = &data_020fe4a8;
    o.h0     = 0;
    o.h1     = 0;
    o.h2     = 0;
    o.w      = 0;
    o.f24[1] = 0;
    func_0204f760(&o, range);

    zp = box.v;
    do {
        *zp++ = 0;
    } while (zp < box.v + 6);
    sum.x = 0;
    sum.y = 0;
    sum.z = 0;
    count = 0;
    func_0204f53c(&o, &box);
    func_020555c4(&it, (s32) &data_021094ac, &box);
    while (!func_02055684(&it)) {
        for (n = (Link *) func_02055660(&it); n != NULL; n = n->next) {
            Ent *e       = n->obj;
            Shape *shape = e->shape;
            if (e != (Ent *) arg1 && shape != NULL && func_01ff84bc(&o, shape)) {
                sum.x += shape->x;
                sum.y += shape->y;
                sum.z += shape->z;
                count++;
            }
        }
        func_02055630(&it);
    }
    if (count <= 0) {
        return;
    }
    div.v = count << FX_SHIFT;
    vec_div_b(&sum, div);
    func_0201807c(&ang, arg1, &sum, 0);
    if (ang_diff(ang.v, arg1->yaw) < 0) {
        Ang step;
        step.v = TURN_POS;
        key_turn3(arg0, step);
    } else {
        Ang step;
        step.v = TURN_NEG;
        key_turn3(arg0, step);
    }
    reach   = fx_mul(range.v, REACH_SCALE);
    dist_sq = (s64) (sum.x - arg1->pos.x) * (sum.x - arg1->pos.x) + (s64) (sum.y - arg1->pos.y) * (sum.y - arg1->pos.y) +
              (s64) (sum.z - arg1->pos.z) * (sum.z - arg1->pos.z);
    *(volatile u16 *) REG_SQRTCNT = SQRT_MODE_64;
    *(u64 *) REG_SQRT_PARAM       = dist_sq << 2;
    while (*(volatile u16 *) REG_SQRTCNT & MATH_BUSY) {
    }
    dist = reach - (((s32) * (volatile u32 *) REG_SQRT_RESULT + 1) >> 1);
    if (dist < 0) {
        dist = 0;
    }
    arg0->f4 = (fx_mul(fx_mul(dist, dist), FX_Div(F4_SPAN, fx_mul(reach, reach))) >> FX_SHIFT) + F4_BASE;
}
