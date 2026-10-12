#include "m2c.h"

void func_02016bbc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x212) == 0xA1) {
        M2C_FIELD(arg0, s8 *, 0x214) = 0x19;
        M2C_FIELD(arg0, s8 *, 0x1C0) = 1;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1D8) = (s8) (M2C_FIELD(arg0, s8 *, 0x1D8) + 1);
}
