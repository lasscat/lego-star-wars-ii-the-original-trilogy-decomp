#include "m2c.h"

s32 func_020648e4(void *arg0, void *arg1, void *arg2) {
    s32 temp_lr;
    s32 temp_r5_2;
    s32 var_r3;
    u8 temp_r0;
    void *temp_ip;
    void *temp_r5;

    var_r3 = 0;
    {
        u8 idx    = M2C_FIELD(arg0, u8 *, 0x55);
        temp_r5   = (void *) (arg0 + (idx * 2));
        temp_r5_2 = M2C_FIELD(temp_r5, u8 *, 0x4B) << 0xC;
        temp_lr   = M2C_FIELD(temp_r5, u8 *, 0x4A) << 0xC;
    }
    M2C_FIELD(arg1, volatile s32 *, 0) = temp_lr;
    M2C_FIELD(arg1, volatile s32 *, 4) = temp_r5_2;
    M2C_FIELD(arg2, volatile s32 *, 0) = temp_lr;
    M2C_FIELD(arg2, volatile s32 *, 4) = temp_r5_2;
    {
        u8 b                                                 = M2C_FIELD(arg0, u8 *, 0x55);
        M2C_FIELD((void *) 0x04000280, volatile u16 *, 0)    = 0U;
        M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x10) = (s32) (b + 4);
    }
    M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x18) = 5;
    M2C_FIELD((void *) 0x04000280, volatile s32 *, 0x1C) = 0;
    do {

    } while (M2C_FIELD((void *) 0x04000280, volatile u16 *, 0) & 0x8000);
    temp_ip = arg0 + (*(s32 *) 0x040002A8 * 2);
    temp_r0 = M2C_FIELD(temp_ip, volatile u8 *, 0x4A);
    if (temp_r0 != 0xFF) {
        M2C_FIELD(arg1, volatile s32 *, 0) = (s32) (temp_r0 << 0xC);
        M2C_FIELD(arg1, volatile s32 *, 4) = (s32) (M2C_FIELD(temp_ip, volatile u8 *, 0x4B) << 0xC);
        if ((M2C_FIELD(arg1, volatile s32 *, 0) == M2C_FIELD(arg2, volatile s32 *, 0)) &&
            (M2C_FIELD(arg1, volatile s32 *, 4) == M2C_FIELD(arg2, volatile s32 *, 4))) {

        } else {
            var_r3 = 1;
        }
    }
    return var_r3;
}
