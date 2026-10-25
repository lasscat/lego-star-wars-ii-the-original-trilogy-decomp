/* Reconstructed from USA ARM9 at 0x020be88c (164 bytes).
 *
 * Offsets the position vector of the object by a table entry selected by
 * the object's index; if the vector changed it is stored and the object
 * is flagged as dirty.
 */
#include "m2c.h"

extern s32 data_0210e2f8[];

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

void func_020be88c(void *arg0, Obj *obj) {
    Vec3 tmp;
    s32 d = data_0210e2f8[obj->index];

    s32 z = obj->pos.z + d;
    s32 y = obj->pos.y + d;
    s32 x = obj->pos.x + d;

    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
    if (!Vec3_NotEqual(&obj->pos, &tmp)) {
        return;
    }
    Vec3_Copy(&tmp, &obj->pos);
    obj->dirty = 1;
}
