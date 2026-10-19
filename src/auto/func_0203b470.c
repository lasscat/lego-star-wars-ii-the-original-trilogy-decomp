#include "m2c.h"

M2C_UNK func_0201c858(void *, u32, u16);            /* extern */
extern M2C_UNK data_020ff9b4;

void func_0203b470(void *arg0) {
    u32 var_r4;
    void *temp_r0;
    void *temp_r2;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r0                    = M2C_FIELD(arg0, void **, 4);
    temp_r2                    = temp_r0 + 0x60;
    if (temp_r2 != &data_020ff9b4) {
        M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    var_r4                       = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0x180);
    do {
        func_0201c858(arg0 + 0x24, var_r4,
                      M2C_FIELD((M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xE0) + (var_r4 * 2)), u16 *, 0x16));
        var_r4 += 1;
    } while (var_r4 < 4U);
}
