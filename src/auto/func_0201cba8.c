#include "m2c.h"

M2C_UNK func_0200bd6c(void *, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK data_020fd1d0;

void *func_0201cba8(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_0200bd6c(arg0, arg1, arg2, 0x276, arg8);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd1d0;
    M2C_FIELD(arg0, s8 *, 0x1D1) = (s8) arg4;
    M2C_FIELD(arg0, s8 *, 0x1D2) = arg3;
    M2C_FIELD(arg0, s8 *, 0x1D3) = (s8) arg5;
    M2C_FIELD(arg0, s8 *, 0x1D4) = (s8) arg6;
    M2C_FIELD(arg0, s8 *, 0x1D5) = (s8) arg7;
    return arg0;
}
