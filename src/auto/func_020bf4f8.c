/* Reconstructed from USA ARM9 at 0x020bf4f8 (320 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 func_02062b10(s32);

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    s32 value;
} Scale;

typedef struct {
    u8 pad0[0x14];
    s32 chance;
    s32 rangeX;
    s32 rangeY;
    s32 rangeZ;
} Jitter;

typedef struct {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad30[0x45 - 0x30];
    u8 dirty;
} Target;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

static inline s32 vec_differs(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *dst, const Vec3 *src) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

void func_020bf4f8(Jitter *jitter, Target *target, Scale scale) {
    Vec3 v;
    s32 r;

    if ((s32) func_02062b10(0x1000) > FxMul(jitter->chance, scale.value)) {
        return;
    }
    v.x = target->pos.x;
    v.y = target->pos.y;
    v.z = target->pos.z;
    r   = jitter->rangeX;
    v.x += func_02062b10((r & 0x7fff) << 1) - r;
    r = jitter->rangeY;
    v.y += func_02062b10((r & 0x7fff) << 1) - r;
    r = jitter->rangeZ;
    v.z += func_02062b10((r & 0x7fff) << 1) - r;
    if (vec_differs(&target->pos, &v)) {
        vec_set(&target->pos, &v);
        target->dirty = 1;
    }
}
