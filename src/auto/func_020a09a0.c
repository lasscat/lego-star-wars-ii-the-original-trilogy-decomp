#include "engine.h"
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 v;
} Ang;

typedef struct {
    u8 pad0[0xb0];
    Vec3 pos;
    u8 padbc[0xc];
    Ang rot_x;
    Ang rot_y;
} Base;

typedef struct Obj {
    u8 pad0[0x28];
    Vec3 pos;
    u8 pad34[0x15];
    u8 f49;
    u8 pad4a[0x186];
    Base *base;
    u8 pad1d4[0x16c];
    Vec3 offset;
} Obj;

/* fx32 (20.12 fixed point) multiply with rounding: (a * b + FX32_HALF) >> FX32_SHIFT */
enum {
    FX32_SHIFT = 12,
    FX32_HALF  = 0x800
};

/* sin/cos table: pairs {sin, cos} indexed by (angle >> 4) * 2 */
extern const s16 data_020f88c4[];

void func_020a019c(Obj *obj, void *arg1);

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

/* rotate v about the X axis by ang */
static inline void rotX(Vec3 *v, u16 ang) {
    s32 s, c, y, z, t;
    int i;
    i = ang >> 4;
    i *= 2;
    s    = data_020f88c4[i];
    c    = data_020f88c4[i + 1];
    y    = v->y;
    z    = v->z;
    t    = (s32) (((s64) z * s + FX32_HALF) >> FX32_SHIFT);
    v->y = (s32) (((s64) y * c + FX32_HALF) >> FX32_SHIFT) - t;
    v->z = (s32) (((s64) y * s + FX32_HALF) >> FX32_SHIFT);
    t    = (s32) (((s64) z * c + FX32_HALF) >> FX32_SHIFT);
    t += v->z;
    v->z = t;
}

/* rotate v about the Y axis by ang */
static inline void rotY(Vec3 *v, u16 ang) {
    s32 s, c, x, z, t;
    int i;
    i = ang >> 4;
    i *= 2;
    s    = data_020f88c4[i];
    c    = data_020f88c4[i + 1];
    x    = v->x;
    z    = v->z;
    v->z = (s32) (((s64) z * s + FX32_HALF) >> FX32_SHIFT);
    t    = (s32) (((s64) x * c + FX32_HALF) >> FX32_SHIFT);
    v->x = t + v->z;
    v->z = (s32) (((s64) x * s + FX32_HALF) >> FX32_SHIFT);
    t    = (s32) (((s64) z * c + FX32_HALF) >> FX32_SHIFT);
    v->z = t - v->z;
}

static inline void vadd(Vec3 *d, const Vec3 *a, const Vec3 *b) {
    d->y = a->y + b->y;
    d->z = a->z + b->z;
    d->x = a->x + b->x;
}

static inline void transform1(Obj *obj, Vec3 *out, const Vec3 *in) {
    Base *b = obj->base;
    Vec3 p;
    Vec3 v;
    p.y = b->pos.y;
    p.z = b->pos.z;
    v.x = in->x;
    v.y = in->y;
    v.z = in->z;
    rotX(&v, b->rot_x.v);
    rotY(&v, b->rot_y.v);
    p.x = b->pos.x + v.x;
    p.y += v.y;
    p.z += v.z;
    out->x = p.x;
    out->y = p.y;
    out->z = p.z;
}

static inline void transform(Obj *obj, Vec3 *out, const Vec3 *in) {
    Base *b = obj->base;
    Vec3 v;
    v.x = in->x;
    v.y = in->y;
    v.z = in->z;
    rotX(&v, b->rot_x.v);
    rotY(&v, b->rot_y.v);
    vadd(&v, &b->pos, &v);
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
}

/*
 * pos = base->pos + rotY(rotX(obj->offset)); when it differs from obj->pos,
 * copy it there and set obj->f49. Then transform the fixed point (0, 10.0, 30.0)
 * the same way and pass it to func_020a019c.
 */
void func_020a09a0(Obj *obj) {
    Vec3 out;
    Vec3 pos;
    Vec3 tmp;

    if (obj->base == 0) {
        return;
    }
    transform1(obj, &pos, &obj->offset);
    if (vec_ne(&obj->pos, &pos)) {
        vec_set(&obj->pos, &pos);
        obj->f49 = 1;
    }
    out.x = 0;
    out.y = 0;
    out.z = 0;
    {
        Vec3 d;
        d.x = 0;
        d.y = 0xa000;
        d.z = 0x1e000;
        transform(obj, &tmp, &d);
    }
    vec_set(&out, &tmp);
    func_020a019c(obj, &out);
}
