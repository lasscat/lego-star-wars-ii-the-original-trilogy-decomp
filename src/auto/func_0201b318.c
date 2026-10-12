#include "m2c.h"

void func_0201b318(void *arg0, u8 arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0x1B) != arg1) || ((M2C_FIELD(arg0, s32 *, 8) & 0x40) == 0x40)) {
        M2C_FIELD(arg0, u8 *, 0x1B) = arg1;
        M2C_FIELD(arg0, u8 *, 0x18) = (u8) M2C_FIELD(arg0, u8 *, 0x19);
        if (M2C_FIELD(arg0, u8 *, 0x1A) != M2C_FIELD(arg0, u8 *, 0x1B)) {
            M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x40);
        }
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~0x10000);
}
