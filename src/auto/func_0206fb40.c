#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_02072bc8();                            /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02102900;
extern M2C_UNK data_0210794c;

void func_0206fb40(void *arg0) {
    if ((u32) M2C_FIELD(&data_021027f8, u8 *, 0x29) > 1U) {
        func_020b04f0(&data_0210794c, 0xC, 0, 0xFF);
        M2C_FIELD(arg0, s32 *, 0x8C) = 0xA;
        return;
    }
    func_02072bc8();
    func_0205ecc4(&data_02102900, 0x20, 1, 0, 0, 0);
}
