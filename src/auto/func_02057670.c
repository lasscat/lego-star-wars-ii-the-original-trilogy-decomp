#include "m2c.h"

void *func_020aaeb4(s32, s32, s32, s32); /* extern */

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 unk[0x250];
    Vec3 pos;
} Big;

void func_02057670(M2C_UNK arg0, Vec3s *arg1) {
    Big *g;
    Vec3 *src;
    s16 vy;
    s32 x, y, z;
    Vec3 t;

    src = &t;
    vy  = arg1->y;
    z   = arg1->z << 12;
    x   = arg1->x << 12;
    y   = vy << 12;
    t.x = x;
    t.y = y;
    t.z = z;

    g = func_020aaeb4(x, y, vy, z);
    if (&g->pos == src) {
        return;
    }
    g->pos.x = src->x;
    g->pos.y = src->y;
    g->pos.z = src->z;
}
