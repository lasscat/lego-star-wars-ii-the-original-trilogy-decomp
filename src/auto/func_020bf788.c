#include "m2c.h"

void *func_020be664();                              /* extern */

void *func_020bf788(void *arg0) {
    void *temp_r0;

    temp_r0 = func_020be664();
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (1 << (M2C_FIELD(temp_r0, u8 *, 0) + 0xF));
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (1 << (M2C_FIELD(temp_r0, u8 *, 1) + 0xF));
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (1 << (M2C_FIELD(temp_r0, u8 *, 2) + 0xF));
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(temp_r0, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_r0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_r0, s32 *, 0xC);
    return temp_r0 + 0x10;
}
