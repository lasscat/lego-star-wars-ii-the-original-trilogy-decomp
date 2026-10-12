#include "m2c.h"

void func_0206d0a8(void *arg0, s32 arg1) {
    void *temp_ip;

    temp_ip = arg0 + (arg1 << 5);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_ip, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(temp_ip, s32 *, 0x10);
    M2C_FIELD(arg0, u16 *, 0x88A) = (u16) M2C_FIELD(temp_ip, u16 *, 0x16);
    M2C_FIELD(arg0, u16 *, 0x888) = (u16) M2C_FIELD(temp_ip, u16 *, 0x14);
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
}
