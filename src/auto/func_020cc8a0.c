#pragma opt_propagation off
#include "m2c.h"
M2C_UNK func_020ccb34(s32);
extern M2C_UNK data_02101540;
extern M2C_UNK data_021153c0;
extern M2C_UNK data_021153c4;
extern M2C_UNK data_021153c8;
extern M2C_UNK data_027e0000;
void func_020cc8a0(s32 arg0) {
    s32 mask, temp_r5, enable, val;
    M2C_UNK (*temp_r1)(s32);
    temp_r5                                       = arg0 * 0xC;
    mask                                          = 1 << M2C_FIELD(&data_02101540, u16 *, arg0 * 2);
    temp_r1                                       = M2C_FIELD(&data_021153c0, M2C_UNK *, temp_r5);
    M2C_FIELD(&data_021153c0, M2C_UNK *, temp_r5) = 0;
    if (temp_r1 != NULL) {
        temp_r1(M2C_FIELD(&data_021153c8, M2C_UNK *, temp_r5));
    }
    val                                      = M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) | mask;
    enable                                   = M2C_FIELD(&data_021153c4, M2C_UNK *, temp_r5);
    M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) = val;
    if (enable != 0) {
        return;
    }
    func_020ccb34(mask);
}
