#include "m2c.h"

extern M2C_UNK data_020f861c;

void func_020b9c4c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) ((arg1 * 0xC) + (s32) &data_020f861c);
}
