#include "m2c.h"

s32 func_02062a7c(s32, s32);
u8 *func_020949b8(u8 *, s32 *, s32, u32);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;
typedef struct {
    u8 pad[0xc];
    s32 x;
    s32 y;
    s32 z;
    u8 pad2[8];
    u16 flags;
    u8 b22;
} Cmd;

void func_02094bf0(u8 *self, Vec3 *pos, Vec3 *src, s32 flag) {
    s32 v[3];
    s32 x;
    s32 y;
    s32 z;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 a = func_02062a7c(1, 4);
    s32 b = func_02062a7c(-5, 5);
    Cmd *res;

    x    = pos->x;
    y    = pos->y;
    z    = pos->z;
    t0   = x + (b << 12);
    t1   = y + (a << 12);
    t2   = z;
    v[0] = t0;
    v[1] = t1;
    v[2] = t2;
    res  = (Cmd *) func_020949b8(self, v, flag, 1);
    if ((u8 *) res + 0xc != (u8 *) src) {
        res->x = src->x;
        res->y = src->y;
        res->z = src->z;
    }
    if (M2C_FIELD(self, u8 *, 0xf7) != 0) {
        res->y = 0;
    }
    res->flags |= 8;
    res->b22 = 0x96;
}
