#include "m2c.h"

M2C_UNK func_020534e0(void *);                      /* extern */
M2C_UNK func_0206549c(void *);                      /* extern */
M2C_UNK func_0206d4d0(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020887fc(void *);                      /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020ff9e8;

void *func_02098790(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff9e8;
    func_020887fc(arg0 + 0x2C);
    func_020534e0(arg0 + 0x2A98);
    func_0206d4d0(arg0 + 0x2AA0, 1, 4, 2, 3);
    func_0206549c(arg0 + 0x2ACC);
    M2C_FIELD(arg0, s32 *, 0x2B18) = 0x80000000;
    return arg0;
}
