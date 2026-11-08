#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} FxVec;

typedef struct {
    u16 v;
} H;

typedef struct {
    u16 v;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} Key;

typedef struct {
    u8 pad0[0xc];
    u16 fc;
    u8 pad_e[0xb0 - 0xe];
    Vec3 pos;
    u8 pad_bc[0xca - 0xbc];
    H fca;
} Target;

typedef struct {
    void *vptr;
    s32 p0;
    s32 p1;
    s32 p2;
    s32 f10;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 sum;
    u8 f24[4];
    s32 b0;
    s32 b1;
    s32 b2;
} Obj;

typedef struct {
    u16 mode;
    u16 pad;
    u32 result;
    u64 input;
} CPRegs;

extern M2C_UNK data_020fcd18;
extern M2C_UNK data_020fe438;
extern M2C_UNK data_021094ac;

void func_0202732c(void *arg0);
void func_0200af88(s8 *arg0, s8 arg1);
void func_0204c594(Obj *o, Vec3 *src);
s32 func_02055474(void *arg0, Obj *arg1, Target **arg2, s32 arg3);
s16 func_020985d8(s32 a, s32 b);
s32 FX_Div(s32, s32);

/* NDS math unit: SQRTCNT 0x040002B0 (bit 0 = 64-bit input, bit 15 = busy), SQRT_RESULT 0x040002B4. */
enum {
    REG_SQRTCNT_ADDR     = 0x40002B0,
    REG_SQRT_RESULT_ADDR = 0x40002B4
};
enum {
    SQRT_MODE_64BIT = 1,
    SQRT_BUSY       = 0x8000
};
/* Binary angles (0x10000 = 360 degrees) and 20.12 fixed-point values. */
enum {
    ANGLE_10_DEG  = 0x71c,
    ANGLE_30_DEG  = 0x1555,
    ANGLE_180_DEG = 0x8000
};
enum {
    FX_15  = 0xf000,
    FX_100 = 0x64000,
    FX_225 = 0xe1000
};

static inline void vec_set(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline s32 abs_s(s32 x) {
    return x < 0 ? -x : x;
}

static inline u16 yaw(Fx x, Fx z) {
    return func_020985d8(x.v, z.v);
}

static inline s32 fx_div(s32 a, Fx b) {
    return FX_Div(a, b.v);
}

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

/* |v| in 20.12: hardware sqrt of 4 * |v|^2, halved with rounding. */
static inline s32 vec_mag(const FxVec *v) {
    volatile CPRegs *cp = (CPRegs *) REG_SQRTCNT_ADDR;
    s64 d               = (s64) v->x.v * v->x.v;
    d += (s64) v->y.v * v->y.v;
    d += (s64) v->z.v * v->z.v;
    cp->mode  = SQRT_MODE_64BIT;
    cp->input = d << 2;
    while (cp->mode & SQRT_BUSY) {
    }
    return (*((volatile s32 *) REG_SQRT_RESULT_ADDR) + 1) >> 1;
}

void func_02027c70(Key *out, Target *self, s32 mask) {
    Target *list[16];
    Obj o;
    FxVec diff;
    Vec3 ext;
    s32 n;
    s32 i;
    s32 cnt;
    s32 sx, sy, sz;
    u16 ang;
    s16 sang;
    s32 dist;
    s32 k;
    s32 s;
    Fx div;
    Fx dz, dy, dx;
    Fx qz;
    Fx qx;
    H a1, a2, a3;
    H head;
    H b1, b2, b3;

    func_0202732c(out);
    ext.x  = FX_15;
    o.vptr = &data_020fcd18;
    ext.y  = FX_15;
    ext.z  = FX_15;
    o.p0   = self->pos.x;
    o.p1   = self->pos.y;
    o.p2   = self->pos.z;
    o.f10  = 0;
    o.a0   = 0;
    o.a1   = 0;
    o.a2   = 0;
    o.sum  = 0;
    func_0200af88((s8 *) &o.f24[0], -1);
    o.f24[2] = 0;
    o.vptr   = &data_020fe438;
    o.b0     = 0;
    o.b1     = 0;
    o.b2     = 0;
    o.f24[1] = 5;
    func_0204c594(&o, &ext);
    sx  = 0;
    sy  = 0;
    sz  = 0;
    cnt = 0;
    n   = func_02055474(&data_021094ac, &o, list, 16);
    for (i = 0; i < n; i++) {
        Target *t = list[i];
        if ((mask & t->fc) && t != self) {
            sx += t->pos.x;
            sy += t->pos.y;
            sz += t->pos.z;
            cnt++;
        }
    }
    if (cnt <= 0) {
        return;
    }
    div.v = cnt << 12;
    dx    = div;
    sx    = fx_div(sx, dx);
    dy    = div;
    sy    = fx_div(sy, dy);
    dz    = div;
    sz    = fx_div(sz, dz);
    vec_set((s32 *) &diff, sx - self->pos.x, sy - self->pos.y, sz - self->pos.z);
    head = self->fca;
    qz   = diff.z;
    qx   = diff.x;
    ang  = yaw(qx, qz) - head.v;
    dist = vec_mag(&diff);
    s    = FX_15 - dist;
    if (s < 0) {
        s = 0;
    }
    /* k = 100 * (s / 15.0)^2 (FX_225 is 15.0 squared). */
    k    = FX_Div(FX_100, FX_225);
    k    = fx_mul(fx_mul(s, s), k) >> 12;
    sang = (s16) ang;
    if (sang < 0) {
        a1.v   = ANGLE_10_DEG;
        b1     = a1;
        out->v = b1.v;
    } else {
        a2.v   = -ANGLE_10_DEG;
        b2     = a2;
        out->v = b2.v;
    }
    out->f4 = k;
    /* within 30 degrees of the heading, or more than 150 degrees off it */
    if (abs_s(sang) < ANGLE_30_DEG) {
        out->f2 = 0;
        out->f5 = k;
    } else {
        s32 m = abs_s(sang);
        a3.v  = ANGLE_30_DEG;
        b3    = a3;
        if (m > (s16) (u16) (ANGLE_180_DEG - b3.v)) {
            out->f2 = 1;
            out->f5 = k;
        }
    }
}
