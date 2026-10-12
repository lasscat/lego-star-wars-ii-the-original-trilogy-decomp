#include "m2c.h"

extern M2C_UNK data_0210db14;

void func_020b94e4(void) {
    M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) | 0x80);
}
