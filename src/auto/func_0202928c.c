#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad[0xb0];
    Vec3 pos;
} Obj;

void func_0202928c(s32 *out, Obj *obj, Vec3 *p) {
    s64 t;
    s32 dx, dy, dz;

    if (obj == 0) {
        *out = 0;
        *out -= 0x80000001;
        return;
    }
    dx = obj->pos.x - p->x;
    dy = obj->pos.y - p->y;
    dz = obj->pos.z - p->z;
    t  = (s64) dz * dz;
    t += (s64) dx * dx + (s64) dy * dy;
    *(volatile u16 *) 0x040002B0 = 1;
    *(u64 *) 0x040002B8          = t << 2;
    while (*(volatile u16 *) 0x040002B0 & 0x8000) {
    }
    *out = ((s32) * (volatile u32 *) 0x040002B4 + 1) >> 1;
}
