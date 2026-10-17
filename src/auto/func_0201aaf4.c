#include "m2c.h"

extern M2C_UNK data_027e01fc;
extern M2C_UNK data_027e01fd;

void func_0201aaf4(s32 arg0, s32 arg1, void *arg2) {
    M2C_FIELD(arg2, u8 *, 0) = (u8) * ((u8 *) ((s8 *) &data_027e01fc + (arg0 * 0x10)) + (arg1 * 4));
    M2C_FIELD(arg2, u8 *, 1) = (u8) * ((u8 *) ((s8 *) &data_027e01fd + (arg0 * 0x10)) + (arg1 * 4));
}
