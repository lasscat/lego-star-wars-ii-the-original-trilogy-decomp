#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */

void *func_0205ebe8(void *arg0) {
    func_0205e624(arg0, 0, 8);
    func_0205e624(arg0 + 8, 0, 0x40);
    func_0205e624(arg0 + 0x48, 0, 0x40);
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0xD4) = 0;
    M2C_FIELD(arg0, s32 *, 0xD8) = 0;
    M2C_FIELD(arg0, s8 *, 0x90) = 0;
    M2C_FIELD(arg0, s8 *, 0x91) = 0;
    M2C_FIELD(arg0, s8 *, 0xDC) = 0;
    M2C_FIELD(arg0, s8 *, 0xDD) = 0;
    return arg0;
}
