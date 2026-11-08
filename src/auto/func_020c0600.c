/* Reconstructed from USA ARM9 at 0x020c0600 (228 bytes).
 *
 * Two-table sibling of func_020be930: the entries of data_0210e3f8 and
 * data_0210e2f8 selected by the object's index are scaled by the value
 * argument (rounded fixed-point multiply) and added to the y and x
 * components of the position vector; z is kept.  If the vector changed it
 * is stored back and the object is flagged as dirty.
 *
 * dy/dx are plain int while the vector fields are s32 (long): with that
 * mix the adds come out as "pos + delta" like the target.
 */
#include "m2c.h"

extern s32 data_0210e2f8[];
extern s32 data_0210e3f8[];

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 unk00[0x30];
    Vec3 pos;
    u8 unk3C[9];
    u8 dirty;
    u8 unk46[6];
    s32 index;
} Obj;

typedef struct {
    s32 v;
} UnkVal;

static inline s32 Vec3_NotEqual(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void Vec3_Copy(const Vec3 *src, Vec3 *dst) {
    if (dst != src) {
        dst->x = src->x;
        dst->y = src->y;
        dst->z = src->z;
    }
}

static inline s32 Fx_Mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800LL) >> 12);
}

void func_020c0600(void *arg0, Obj *obj, UnkVal scale) {
    Vec3 tmp;
    int dy = Fx_Mul(data_0210e3f8[obj->index], scale.v);
    int dx = Fx_Mul(data_0210e2f8[obj->index], scale.v);
    s32 z  = obj->pos.z;

    dy    = obj->pos.y + dy;
    dx    = obj->pos.x + dx;
    tmp.x = dx;
    tmp.y = dy;
    tmp.z = z;
    if (!Vec3_NotEqual(&obj->pos, &tmp)) {
        return;
    }
    Vec3_Copy(&tmp, &obj->pos);
    obj->dirty = 1;
}
