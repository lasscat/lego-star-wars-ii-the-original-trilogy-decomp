#include "m2c.h"

extern u8 *data_0210daf0;
extern u32 data_0210dafc[];
extern u8 data_0210dc24[2][16];

void func_020b7f90(u8, u32);
s32 func_020bb36c(s32);
void func_020bb6b0(u32, s32);

void func_020bb3f8(s32 arg0, u8 arg1) {
    u8 cur = data_0210dc24[0][arg0];

    switch (cur & 0xe0) {
        case 0x00: {
            u8 *saved     = data_0210daf0;
            data_0210daf0 = (u8 *) data_0210dafc[cur & 0x1f];
            func_020b7f90(arg0 & 0xff, 0);
            data_0210daf0 = saved;
        } break;
        case 0x20:
            func_020bb6b0(func_020bb36c(cur & 0x1f), 0);
            break;
        case 0xe0:
            break;
    }

    data_0210dc24[0][arg0] = arg1;
    data_0210dc24[1][arg0] = 0xff;
}
