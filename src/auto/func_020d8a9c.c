#include "m2c.h"

M2C_UNK func_020d8ae8(s32, s32, M2C_UNK);           /* extern */
s32 func_020d9c54();                                /* extern */
extern s32 data_0211e40c;

void func_020d8a9c(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (func_020d9c54() != 0) {
        M2C_FIELD((data_0211e40c + ((arg0 - 1) * 4)), s32 *, 0x14E8) = arg1;
    }
    func_020d8ae8(arg0, arg1, arg2);
}
