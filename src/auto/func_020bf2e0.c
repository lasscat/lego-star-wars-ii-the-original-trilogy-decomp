/* Reconstructed from USA ARM9 at 0x020bf2e0 (244 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    s32 value;
} Scale;

typedef struct {
    u8 pad0[0x14];
    s32 scale;
} Ctl;

typedef struct {
    u8 pad0[0x54];
    Vec3 v;
} Target;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

static inline void vec_set(Vec3 *dst, const Vec3 *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

void func_020bf2e0(Ctl *self, Target *t, Scale scale) {
    s32 f  = 0x1000 - self->scale;
    s32 x0 = t->v.x;
    s32 y0 = t->v.y;
    s32 z0 = t->v.z;
    s32 wz = FxMul(z0, f);
    s32 wy = FxMul(y0, f);
    s32 wx = FxMul(x0, f);
    s32 dz = FxMul(wz, scale.value);
    s32 dy = FxMul(wy, scale.value);
    s32 dx = FxMul(wx, scale.value);
    Vec3 v;
    v.x = x0 - dx;
    v.y = y0 - dy;
    v.z = z0 - dz;
    vec_set(&t->v, &v);
}
