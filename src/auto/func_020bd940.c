#include "m2c.h"
void *func_020bd940(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 4) = M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 6) = M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 7) = M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 7) |= M2C_FIELD(arg1, u8 *, 3) << 1;
    M2C_FIELD(arg0, u8 *, 7) |= M2C_FIELD(arg1, u8 *, 4) << 2;
    M2C_FIELD(arg0, u8 *, 7) |= M2C_FIELD(arg1, u8 *, 5) << 3;
    return arg1 + 6;
}
