#include "m2c.h"

M2C_UNK func_02053c2c(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_0206574c(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_02065be8(void *, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */

void func_0206f200(void *arg0) {
    s32 temp_r5;
    s32 temp_r5_2;

    func_02053c2c(arg0 + 0x84, 0, 0xD, 0x20, 4, 0);
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x8C);
    func_0206574c(arg0 + 0x54, 6, -1);
    if (M2C_FIELD(arg0, u8 *, 0x90) == 1) {
        func_0206574c(arg0 + 0x54, 3, -2);
    } else {
        func_0206574c(arg0 + 0x54, 0, -2);
    }
    temp_r5_2 = func_02065be8(arg0 + 0x54, temp_r5, 0x40, 0x78, func_02066708(0x56), 1);
    if (M2C_FIELD(arg0, u8 *, 0x90) == 2) {
        func_0206574c(arg0 + 0x54, 3, -2);
    } else {
        func_0206574c(arg0 + 0x54, 0, -2);
    }
    func_02065be8(arg0 + 0x54, temp_r5_2, 0xC0, 0x78, func_02066708(0x57), 1);
    func_0206574c(arg0 + 0x54, 0, -2);
}
