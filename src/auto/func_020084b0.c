#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    s32 value;
} Fixed;
typedef struct {
    Fixed x, y, z;
} Scale;
typedef struct {
    s32 matrix[9];
    Vec3 position;
    Scale scale;
    u16 rotation[4];
    u8 rotationDirty;
    u8 matrixDirty;
} Transform;
typedef struct {
    Vec3 offset;
    u8 flag;
    u8 unknown0d[2];
    u8 slot;
} Request;
typedef struct {
    u8 unknown00[4];
    Vec3 position;
    u8 unknown10[0x16];
    u8 active;
} Target;
typedef struct {
    u8 unknown00[0x10];
    Target *targets[1];
} Owner;

enum {
    FX_ONE       = 0x1000, /* 1.0 in 20.12 fixed point */
    FX_HALF      = 0x800,  /* rounding term for a 20.12 multiply */
    FX_FRAC_BITS = 12,
};

extern void func_01ffa6f8(s32 *, u16 *);
extern void func_01ffa958(Vec3 *, const void *, const Vec3 *);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline s32 multiplyFixed(s32 value, const Fixed *scale) {
    return (s32) (((s64) value * scale->value + FX_HALF) >> FX_FRAC_BITS);
}

static inline Vec3 *worldOffset(Vec3 *result, Transform *xf, const Vec3 *offset) {
    Fixed z, y, x;
    if (xf->rotationDirty) {
        xf->matrixDirty   = 1;
        xf->rotationDirty = 0;
        func_01ffa6f8(xf->matrix, xf->rotation);
    }
    func_01ffa958(result, xf->matrix, offset);
    if (xf->scale.x.value != FX_ONE || xf->scale.y.value != FX_ONE || xf->scale.z.value != FX_ONE) {
        x         = xf->scale.x;
        result->x = multiplyFixed(result->x, &x);
        y         = xf->scale.y;
        result->y = multiplyFixed(result->y, &y);
        z         = xf->scale.z;
        result->z = multiplyFixed(result->z, &z);
    }
    result->x += xf->position.x;
    result->y += xf->position.y;
    result->z += xf->position.z;
    return result;
}

/* Sets the requested target slot's active flag from the request; when active, moves the
   target to the request offset transformed into world space by xf (rotate, scale, translate).
   unusedByte/unusedType: caller func_0205c774 passes a one-byte struct and a type byte; unused here. */
void func_020084b0(Owner *owner, s32 unusedByte, s32 unusedType, Request *req, Transform *xf) {
    Vec3 position;
    u8 slot = req->slot;
    Target *t;
    Vec3 *from;

    t         = owner->targets[slot];
    t->active = req->flag != 0;
    if (t->active == 0) {
        return;
    }
    t    = owner->targets[slot];
    from = worldOffset(&position, xf, &req->offset);
    vec_set(&t->position, from);
}
