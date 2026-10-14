#include "m2c.h"

extern M2C_UNK func_02022bbc;

void func_02022980(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x212) != 0x54) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x84)      = 0x13;
    M2C_FIELD(arg0, M2C_UNK **, 0x10) = &func_02022bbc;
    M2C_FIELD(arg0, s32 *, 8)         = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x200);
}
