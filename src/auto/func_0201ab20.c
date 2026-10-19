#include "m2c.h"

M2C_UNK func_02001778(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_020cf19c(M2C_UNK, void *, M2C_UNK);    /* extern */
extern M2C_UNK data_020fd0f0;

void *func_0201ab20(void *arg0, M2C_UNK arg1) {
    u16 v;
    func_02001778(arg0, 0x100, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd0f0;
    M2C_FIELD(arg0, s32 *, 0x2C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x30)   = 0;
    M2C_FIELD(arg0, s32 *, 0x34)   = 0;
    M2C_FIELD(arg0, s32 *, 0x38)   = 0;
    M2C_FIELD(arg0, s32 *, 0x4C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x50)   = 0;
    M2C_FIELD(arg0, s32 *, 0x54)   = 0;
    M2C_FIELD(arg0, s32 *, 0x58)   = 0;
    M2C_FIELD(arg0, s32 *, 0x5C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x60)   = 0;
    M2C_FIELD(arg0, s32 *, 0x64)   = 0;
    M2C_FIELD(arg0, s32 *, 0x68)   = 0;
    M2C_FIELD(arg0, s32 *, 0x6C)   = 0;
    M2C_FIELD(arg0, s32 *, 0x70)   = 0;
    M2C_FIELD(arg0, s16 *, 0x78)   = 0;
    M2C_FIELD(arg0, s32 *, 0x7C)   = 0;
    func_020cf19c(0, arg0 + 0x10, 0x3C);
    v                            = 0xFFFF;
    M2C_FIELD(arg0, u16 *, 0x1E) = v;
    M2C_FIELD(arg0, u16 *, 0x42) = v;
    M2C_FIELD(arg0, s32 *, 8)    = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x401401);
    return arg0;
}
