#include "m2c.h"

typedef struct {
    s32 v;
} Fx;

typedef struct {
    u16 v;
} Angle;

typedef struct {
    Fx x;
    Fx y;
    Fx z;
} V3;

typedef struct {
    u8 pad0[0xb0];
    V3 cur;
    u8 pad1[0xc4 - 0xbc];
    s32 len;
    u16 pitch;
    u16 yaw;
    u8 pad2[0xd0 - 0xcc];
    u8 dirtyAngle;
    u8 dirtyVec;
    u8 pad3[0x1bc - 0xd2];
    V3 p0;
    V3 p1;
} Obj;

static inline s32 vec_ne(const V3 *a, const V3 *b) {
    if (a->x.v != b->x.v || a->y.v != b->y.v || a->z.v != b->z.v) {
        return 1;
    }
    return 0;
}

static inline void vec_set(V3 *d, const V3 *s) {
    if (d != s) {
        d->x.v = s->x.v;
        d->y.v = s->y.v;
        d->z.v = s->z.v;
    }
}

static inline void vec_sub(V3 *d, const V3 *a, const V3 *b) {
    s32 x, y, z;

    z      = b->z.v;
    z      = a->z.v - z;
    y      = b->y.v;
    y      = a->y.v - y;
    x      = a->x.v - b->x.v;
    d->x.v = x;
    d->y.v = y;
    d->z.v = z;
}

extern s16 func_020985d8(s32, s32);

/* NDS math coprocessor square-root unit (hardware registers, GBATEK map). */
enum {
    REG_SQRTCNT     = 0x40002B0,
    REG_SQRT_RESULT = 0x40002B4,
    REG_SQRT_PARAM  = 0x40002B8
};

enum {
    SQRTCNT_MODE_64BIT = 1,
    SQRTCNT_BUSY       = 0x8000
};

static inline void cp_set_sqrt64(u64 param) {
    *(volatile u16 *) REG_SQRTCNT    = SQRTCNT_MODE_64BIT;
    *(volatile u64 *) REG_SQRT_PARAM = param;
}

static inline void cp_wait_sqrt(void) {
    while (*(volatile u16 *) REG_SQRTCNT & SQRTCNT_BUSY) {
    }
}

static inline u32 cp_sqrt_result(void) {
    return *(volatile u32 *) REG_SQRT_RESULT;
}

static inline void set_angle(Obj *o, u16 *f, Angle v) {
    if (*f != v.v) {
        *f            = v.v;
        o->dirtyAngle = 1;
    }
}

void func_02001b28(Obj *a) {
    V3 d;
    Fx qz, qx, qy, qh;
    s64 xx, zz, sum;
    s32 r;

    vec_sub(&d, &a->p1, &a->p0);
    if (vec_ne(&a->cur, &a->p0)) {
        vec_set(&a->cur, &a->p0);
        a->dirtyVec = 1;
    }
    qz = d.z;
    qx = d.x;
    set_angle(a, &a->yaw, (Angle) {func_020985d8(qx.v, qz.v)});

    xx  = (s64) d.x.v * d.x.v;
    zz  = (s64) d.z.v * d.z.v;
    sum = xx;
    sum += zz;
    sum <<= 2;
    cp_set_sqrt64(sum);
    cp_wait_sqrt();
    qy   = d.y;
    qh.v = ((s32) cp_sqrt_result() + 1) >> 1;
    set_angle(a, &a->pitch, (Angle) {-(u16) func_020985d8(qy.v, qh.v)});

    sum = xx;
    sum += (s64) d.y.v * d.y.v;
    sum += zz;
    sum <<= 2;
    cp_set_sqrt64(sum);
    cp_wait_sqrt();
    r = (cp_sqrt_result() + 1) & ~1;
    if (a->len != r) {
        a->len      = r;
        a->dirtyVec = 1;
    }
}
