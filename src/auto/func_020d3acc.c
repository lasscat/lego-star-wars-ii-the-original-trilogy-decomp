#include "m2c.h"
M2C_UNK func_020cdad4(M2C_UNK *);
M2C_UNK func_020d1134();
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);
s32 func_020d128c(M2C_UNK, M2C_UNK);
extern M2C_UNK data_0211748c;
extern M2C_UNK data_021174b4;
extern M2C_UNK data_021174cc;
extern M2C_UNK func_020d3b70;
void func_020d3acc(void) {
    s32 var_r3;
    if (M2C_FIELD(&data_0211748c, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0211748c, u16 *, 0)    = 1U;
    M2C_FIELD(&data_0211748c, s32 *, 0x18) = 0;
    M2C_FIELD(&data_0211748c, s32 *, 0x1C) = 0;
    func_020d1134();
    while (func_020d128c(8, 1) == 0) {
    }
    func_020d1240(8, &func_020d3b70);
    for (var_r3 = 0; var_r3 < 5; var_r3++) {
        ((u16 *) &data_021174cc)[var_r3 * 4] = 0;
    }
    func_020cdad4(&data_021174b4);
    M2C_FIELD(&data_0211748c, s32 *, 0x10) = *(s32 *) 0x027FFC3C;
}
