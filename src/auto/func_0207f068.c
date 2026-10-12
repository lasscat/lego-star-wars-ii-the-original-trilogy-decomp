#include "m2c.h"

s32 func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_02066118(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020661b4(s32, s32);                    /* extern */
s32 func_02066708(s32);                             /* extern */

void func_0207f068(void *arg0, s32 arg1, s32 arg2) {
    func_02066118(M2C_FIELD(arg0, s32 *, 8), 2, 1, 0x1E);
    func_02066118(M2C_FIELD(arg0, s32 *, 8), 2, 2, 0x1E);
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
    M2C_FIELD(arg0, s32 *, 0x34) = arg2;
    func_020661b4(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 0x2C) = func_02065be8(M2C_FIELD(arg0, s32 *, 8), 0xF0, 0x80, 0xA, func_02066708(0x241), 1);
}
