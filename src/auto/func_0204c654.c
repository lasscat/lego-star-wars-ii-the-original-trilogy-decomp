#include "m2c.h"

void func_0204c654(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0x24) - M2C_FIELD(arg1, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 0x24) + M2C_FIELD(arg1, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg1, s32 *, 0x28) - M2C_FIELD(arg1, s32 *, 0x34));
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg1, s32 *, 0x28) + M2C_FIELD(arg1, s32 *, 0x34));
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C) - M2C_FIELD(arg1, s32 *, 0x38));
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C) + M2C_FIELD(arg1, s32 *, 0x38));
}
