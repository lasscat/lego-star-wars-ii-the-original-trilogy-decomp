/* Reconstructed from USA ARM9 at 0x020bec84 (124 bytes).
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

extern Vec3 data_0210e6f4[];

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

void func_020bec84(void *unused, Object *obj) {
    Vec3 sum;
    vec_add(&obj->pos, &data_0210e6f4[obj->index], &sum);
    vec_copy(&sum, &obj->pos);
}
