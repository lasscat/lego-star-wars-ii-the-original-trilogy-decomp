/* Reconstructed from USA ARM9 at 0x020bed00 (212 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct Object {
    u8 pad0[0x4c];
    s32 index;
    u8 pad1[4];
    Vec3 pos;
} Object;

typedef struct Fixed {
    s32 v;
} Fixed;

extern Vec3 data_0210e6f4[];

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void vec_scale(Vec3 *v, s32 k, Vec3 *out) {
    s32 z  = fx_mul(v->z, k);
    s32 y  = fx_mul(v->y, k);
    s32 x  = fx_mul(v->x, k);
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void vec_add(Vec3 *a, Vec3 *b, Vec3 *out) {
    s32 z  = a->z + b->z;
    s32 y  = a->y + b->y;
    s32 x  = a->x + b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void vec_copy(Vec3 *src, Vec3 *dst) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

void func_020bed00(void *unused, Object *obj, Fixed scale) {
    Vec3 sum;
    Vec3 scaled;
    Vec3 *step = &scaled;

    vec_scale(&data_0210e6f4[obj->index], scale.v, step);
    vec_add(&obj->pos, step, &sum);
    vec_copy(&sum, &obj->pos);
}
