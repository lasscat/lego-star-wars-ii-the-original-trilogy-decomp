#include "m2c.h"
M2C_UNK func_0207b370(s32, s32, s8);
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);
extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210794c;
extern s32 data_027e02a8;
void func_0207b240(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    u8 buf[0x1C];
    u8 idx;
    idx = (u8) arg2;
    if (arg3 == M2C_FIELD((arg1 + (idx * 2)), u16 *, 0x6E8)) {
        return;
    }
    if (data_027e02a8 & 0x40) {
        buf[0] = M2C_FIELD(&data_021027f8, u8 *, 0x2A);
        buf[1] = idx;
        buf[2] = arg3;
        func_020b04f0(&data_0210794c, 0x2E, buf, 0xFF);
        return;
    }
    func_0207b370(arg1, arg2, arg3);
}
