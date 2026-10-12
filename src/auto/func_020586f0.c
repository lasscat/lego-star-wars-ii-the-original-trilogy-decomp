#include "m2c.h"

M2C_UNK func_02086234(M2C_UNK *, u8, s32);          /* extern */
s32 func_02086244(M2C_UNK *, u8);                   /* extern */
extern M2C_UNK data_02104d90;

void func_020586f0(s32 arg0, u8 *arg1) {
    func_02086234(&data_02104d90, *arg1, func_02086244(&data_02104d90, *arg1) - 1);
}
