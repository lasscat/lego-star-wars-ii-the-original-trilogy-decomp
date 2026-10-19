#include "m2c.h"

M2C_UNK func_02058454(M2C_UNK, u8, u8, u8, u8, u8, u8, u8); /* extern */
M2C_UNK func_02058a48(u8, u8, u8, u8, u8, u8, u8);  /* extern */
M2C_UNK func_02086244(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_02104d90;

void func_020585d8(M2C_UNK arg0, u8 *arg1) {
    M2C_UNK var_r5;
    M2C_UNK var_r0;

    func_02058a48(arg1[0], arg1[2], arg1[3], arg1[4], arg1[5], arg1[6], arg1[1]);
    var_r5 = func_02086244(&data_02104d90, arg1[0]);
    var_r0 = func_02086244(&data_02104d90, arg1[2]);
    func_02058454(arg0, var_r5, arg1[1], var_r0, arg1[3], arg1[4], arg1[5], arg1[6]);
}
