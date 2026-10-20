#include "m2c.h"

extern void func_01ff97c4();

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void func_0204f9bc(s32 *out, void *a1, Vec3 *a2, Vec3 *a3, s32 a4) {
    Vec3 d;
    s32 dz = a3->z - a2->z;
    s32 dx = a3->x - a2->x;
    s32 dy = a3->y - a2->y;
    d.x    = dx;
    d.y    = dy;
    d.z    = dz;
    func_01ff97c4(out, a1, a2, &d, a4);
}
