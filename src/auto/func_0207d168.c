#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
M2C_UNK func_0207d59c(void *);                      /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff184;

void *func_0207d168(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff184;
    func_0207d59c(arg0 + 0x28);
    func_020534e0(arg0 + 0x6C);
    func_020534e0(arg0 + 0x74);
    func_0206549c(arg0 + 0x7C);
    func_0206549c(arg0 + 0xAC);
    return arg0;
}
