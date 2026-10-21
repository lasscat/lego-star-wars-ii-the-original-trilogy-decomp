#include "m2c.h"

extern u8 *data_0210daf0;
extern s32 *data_0210098c[];
extern u16 data_020f7c08[];
extern u16 data_020f79c8[];

s32 func_020b8b1c(s32 x, s32 y) {
    s32 a, b;
    s32 t;
    s32 c, d;
    s64 v;

    if (y == 0) {
        return x;
    }
    if (M2C_FIELD(data_0210daf0, u8 *, 0x2d) & 8) {
        if (y > 0) {
            if (y > 0x3ff) {
                y = 0x3ff;
            }
            a = data_0210098c[1][y >> 2];
            b = data_0210098c[0][y & 3];
            a = (x / 64) * (a / 64) / 16 / 64;
            return a * (b / 64) / 16;
        } else if (y >= 0) {
            return x;
        } else {
            y = -y;
            if (y > 0x3ff) {
                y = 0x3ff;
            }
            c = data_020f7c08[y >> 2];
            d = data_020f79c8[y & 3];
            t = (x / 64) * (c / 64) / 16 / 64;
            return t * (d / 64) / 16;
        }
    }
    v = 0xda7600 - (s64) y * (u32) x;
    if (v <= 0) {
        return 0x3fff800;
    }
    M2C_FIELD((void *) 0x04000280, volatile u16 *, 0)    = 2;
    M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x10) = (u32) ((s64) (u32) x * 0xda7600);
    M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x14) = (u32) (((s64) (u32) x * 0xda7600) >> 32);
    M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x18) = (u32) v;
    M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x1C) = (u32) (v >> 32);
    do {
    } while (M2C_FIELD((void *) 0x04000280, volatile u16 *, 0) & 0x8000);
    return *(volatile u32 *) 0x040002a0;
}
