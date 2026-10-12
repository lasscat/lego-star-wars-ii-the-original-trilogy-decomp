#include "m2c.h"

M2C_UNK func_0201b318(void *, u8);                  /* extern */

void func_0201c684(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0xA6) != 0) {
        func_0201b318(arg0, (u8) (M2C_FIELD(arg0, s32 *, 0xA0) + arg1));
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s32 *, 0x14) & ~0xF000) | (u16) ((M2C_FIELD(arg0, s32 *, 0x9C) + arg1) << 0xC));
}
