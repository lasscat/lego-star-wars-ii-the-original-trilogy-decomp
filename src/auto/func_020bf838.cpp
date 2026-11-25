#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} Vec3;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Angle w0;
    Angle w2;
    Angle w4;
    u16 w6;
    s32 w8;
    s32 wc;
} Slot;

typedef struct {
    u8 pad0[8];
    s32 s8;
    s32 sc;
    s32 flag10;
    s32 s14;
    s32 s18;
    s32 s1c;
    s32 s20;
} Src;

typedef struct {
    u8 pad0[0x4c];
    s32 idx;
    u8 pad50[4];
    Vec3 v;
    u8 pad60[0x14];
    s32 scale;
} Cam;

extern "C" Slot data_0210ecf4[];

extern "C" u32 func_02062b10(s32);
extern "C" s16 func_020985d8(s32, s32);
extern "C" s32 FX_Div(s32, s32);

static inline Angle AngleMake(u16 v) {
    Angle a;
    a.v = v;
    return a;
}

static inline void SetAngle(Angle *dst, Angle a) {
    dst->v = a.v;
}

enum {
    FX_HALF = 0x800
};

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + FX_HALF) >> 12);
}

struct Fixed {
    s32 value;
    Fixed() {}
    Fixed(s32 v) :
        value(v) {}
    s32 Int() const {
        return value >> 12;
    }
};

static inline Vec3 *VecCopy(Vec3 *d, const Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    return d;
}

/* DS hardware square root unit (SQRTCNT 0x040002b0, SQRT_RESULT 0x040002b4, SQRT_PARAM 0x040002b8). */
enum {
    REG_SQRTCNT_ADDR     = 0x040002b0,
    REG_SQRT_RESULT_ADDR = 0x040002b4,
    REG_SQRT_PARAM_ADDR  = 0x040002b8,
    SQRT_MODE_64BIT      = 1,
    SQRT_BUSY            = 0x8000
};

/* sqrt(4 * (x*x + z*z)) = 2 * length; (+ 1) >> 1 halves it with rounding. */
static inline s32 HorizontalLength(s32 x, s32 z) {
    s64 t = (s64) x * x;
    t += (s64) z * z;
    *(volatile u16 *) REG_SQRTCNT_ADDR    = SQRT_MODE_64BIT;
    *(volatile u64 *) REG_SQRT_PARAM_ADDR = t << 2;
    while (*(volatile u16 *) REG_SQRTCNT_ADDR & SQRT_BUSY) {
    }
    return (s32) (*(volatile u32 *) REG_SQRT_RESULT_ADDR + 1) >> 1;
}

static inline void Elevation(Angle *out, const Fx &y, s32 h) {
    out->v = -(u16) func_020985d8(y.v, h);
}

static inline void VecPitch(Angle *out, const Vec3 *v) {
    s32 h = HorizontalLength(v->x.v, v->z.v);
    Fx y  = v->y;
    Elevation(out, y, h);
}

static inline void Atan2(Angle *out, const Fx &z, Fx x) {
    out->v = func_020985d8(x.v, z.v);
}

static inline void VecYaw(Angle *out, const Vec3 *v) {
    Fx z = v->z;
    Atan2(out, z, v->x);
}

extern "C" void func_020bf838(Src *a, Cam *b) {
    Angle pitch;
    Angle yaw;
    Vec3 v0;
    Vec3 v1;
    s32 hi;
    s32 lo;
    s32 n;
    Slot *s = &data_0210ecf4[b->idx];
    if (a->flag10 != 0) {
        n = (a->sc - a->s8) >> 12;
    } else {
        n = Fixed(FxMul(a->sc, b->scale)).Int() - Fixed(FxMul(a->s8, b->scale)).Int();
    }
    lo = func_02062b10((u16) (a->s18 - a->s14));
    lo += a->s14;
    hi = func_02062b10((u16) (a->s20 - a->s1c));
    hi += a->s1c;
    s->wc = FX_Div(hi - lo, n << 12);
    s->w8 = lo;
    s->w0 = AngleMake(0);

    // FAKE: re-reads b->idx and recomputes the slot pointer (the target's second ldr [b,#0x4c] after the stores);
    // likely the boundary of an inlined helper, since the code above is the body of func_020bff7c.
    s = &data_0210ecf4[b->idx];
    VecPitch(&pitch, VecCopy(&v0, &b->v));
    SetAngle(&s->w2, pitch);
    VecYaw(&yaw, VecCopy(&v1, &b->v));
    SetAngle(&s->w4, yaw);
}
