#include "m2c.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

extern M2C_UNK data_021019f4;
extern s32 data_027e02a4;

void *func_0203fecc(Vec3 *arg0) {
    void *result;
    void *node;
    void *ent;
    s32 best_dist;

    node      = M2C_FIELD((u8 *) &data_021019f4 + data_027e02a4 * 0x38, void **, 4);
    result    = NULL;
    best_dist = 0x7fffffff;

    while (node != NULL) {
        ent = M2C_FIELD(node, void **, 0);
        if (M2C_FIELD(ent, u16 *, 0xc) == 4 && M2C_FIELD(ent, u16 *, 0x212) == 0x136) {
            s32 dx = M2C_FIELD(ent, s32 *, 0xb0) - arg0->x;
            s32 dy = M2C_FIELD(ent, s32 *, 0xb4) - arg0->y;
            s32 dz = M2C_FIELD(ent, s32 *, 0xb8) - arg0->z;
            s64 t  = (s64) dz * dz;
            s32 dist;
            t += (s64) dx * dx + (s64) dy * dy;

            *(vu16 *) 0x040002b0 = 1;
            *(u64 *) 0x040002b8  = t << 2;
            while (*(vu16 *) 0x040002b0 & 0x8000) {
            }
            dist = ((s32) * (vu32 *) 0x040002b4 + 1) >> 1;
            if (dist < best_dist) {
                result    = ent;
                best_dist = dist;
            }
        }
        node = M2C_FIELD(node, void **, 4);
    }
    return result;
}
