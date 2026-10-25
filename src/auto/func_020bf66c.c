/* Reconstructed from USA ARM9 at 0x020bf66c (264 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0x14];
    s32 rangeX;
    s32 rangeY;
    s32 rangeZ;
    Vec3 offset;
} WrapParams;

typedef struct Target {
    u8 pad0[0x24];
    Vec3 pos;
    u8 pad30[0x45 - 0x30];
    u8 dirty;
    u8 pad46[0x48 - 0x46];
    struct Target *parent;
} Target;

static inline void vec_add(const Vec3 *a, const Vec3 *b, Vec3 *out) {
    s32 z  = a->z + b->z;
    s32 y  = a->y + b->y;
    s32 x  = a->x + b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline void vec_sub(const Vec3 *a, const Vec3 *b, Vec3 *out) {
    s32 z  = a->z - b->z;
    s32 y  = a->y - b->y;
    s32 x  = a->x - b->x;
    out->x = x;
    out->y = y;
    out->z = z;
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

void func_020bf66c(WrapParams *params, Target *target) {
    Vec3 v;
    Vec3 c;
    Vec3 d;
    s32 rx, ry, rz;

    vec_add(&target->parent->pos, &params->offset, &c);
    vec_sub(&target->pos, &c, &d);

    rx  = params->rangeX;
    d.x = ((rx + d.x) & ((rx << 1) - 1)) - rx;
    ry  = params->rangeY;
    d.y = ((ry + d.y) & ((ry << 1) - 1)) - ry;
    rz  = params->rangeZ;
    d.z = ((rz + d.z) & ((rz << 1) - 1)) - rz;

    vec_add(&d, &c, &v);
    if (vec_differs(&target->pos, &v)) {
        vec_set(&target->pos, &v);
        target->dirty = 1;
    }
}
