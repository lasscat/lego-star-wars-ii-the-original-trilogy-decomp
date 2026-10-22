#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
s32 func_0206d4d0(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
void func_020730d0(s32);                            /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fea10;

void *func_0206f354(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6d0;
    M2C_FIELD(arg0, s32 *, 4)      = arg1;
    M2C_FIELD(arg0, s32 *, 8)      = arg2;
    M2C_FIELD(arg0, s32 *, 0xC)    = arg3;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg4;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s32 *, 0x18)   = 0;
    M2C_FIELD(arg0, s32 *, 0x1C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fea10;
    func_020534e0(arg0 + 0x28);
    func_0206d4d0(arg0 + 0x30, 1, 4, 2, 3);
    func_0206549c(arg0 + 0x5C);
    M2C_FIELD(arg0, s32 *, 0x98) = 1;
    M2C_FIELD(arg0, s32 *, 0x9C) = 2;
    M2C_FIELD(arg0, s32 *, 0xA0) = 1;
    if (arg4 == 0) {
        func_020730d0(2);
    } else {
        func_020730d0(4);
    }
    return arg0;
}
