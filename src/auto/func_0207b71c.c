#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
M2C_UNK func_0206d0d8(void *, M2C_UNK);             /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff144;
extern M2C_UNK data_020ff168;

void *func_0207b71c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10) = arg4;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    func_0206d0d8(arg0 + 0x28, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff144;
    M2C_FIELD(arg0, M2C_UNK **, 0x28) = &data_020ff168;
    func_020534e0(arg0 + 0x30);
    func_0206549c(arg0 + 0x38);
    func_0206549c(arg0 + 0x68);
    func_0206d4d0(arg0 + 0x98, 1, 1, 2, 3);
    M2C_FIELD(arg0, s8 *, 0xDC) = 4;
    M2C_FIELD(arg0, s8 *, 0xDD) = 2;
    M2C_FIELD(arg0, s8 *, 0xDE) = 2;
    M2C_FIELD(arg0, s8 *, 0xDF) = 2;
    M2C_FIELD(arg0, s8 *, 0xE0) = 0xA;
    if (arg1 == 0xB) {
        M2C_FIELD(arg0, s8 *, 0xDD) = 0;
    } else if (arg1 == 0xC) {
        M2C_FIELD(arg0, s8 *, 0xDD) = 1;
    }
    return arg0;
}
