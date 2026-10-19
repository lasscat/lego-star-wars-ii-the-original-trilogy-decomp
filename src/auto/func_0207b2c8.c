#include "m2c.h"

M2C_UNK func_0207b3bc(void *, s8);                  /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK); /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210794c;
extern s32 data_027e02a8;

void func_0207b2c8(s32 arg0, void *arg1, s8 arg2) {
    u8 buf[0x1C];

    if (arg2 == M2C_FIELD(arg1, u8 *, 0x6C3)) {
        return;
    }
    if (data_027e02a8 & 0x40) {
        buf[0] = M2C_FIELD(&data_021027f8, u8 *, 0x2A);
        buf[1] = arg2;
        func_020b04f0(&data_0210794c, 0x2F, buf, 0xFF);
        return;
    }
    func_0207b3bc(arg1, arg2);
}
