#include "m2c.h"

M2C_UNK func_02017908(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_020fd0c8;

void *func_0201a3cc(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7) {
    func_02017908(arg0, 0x2000, arg1, arg2);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd0c8;
    M2C_FIELD(arg0, s8 *, 0xD4)    = 0;
    M2C_FIELD(arg0, s32 *, 0xD8)   = arg6;
    M2C_FIELD(arg0, s8 *, 0xDC)    = arg3;
    M2C_FIELD(arg0, s8 *, 0xDD)    = (s8) arg4;
    M2C_FIELD(arg0, s8 *, 0xDE)    = (s8) arg5;
    M2C_FIELD(arg0, u8 *, 0xDF)    = arg7;
    return arg0;
}
