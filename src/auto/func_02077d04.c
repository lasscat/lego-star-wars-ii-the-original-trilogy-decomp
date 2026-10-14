#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK func_020660e4(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_02066c80(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0207a7d8(void *, s32);                 /* extern */

void func_02077d04(void *arg0, s32 arg1) {
    u8 sp8[32];
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r3;
    void *temp_r3_2;

    func_020660e4(arg0 + 0xA0, 0, 0x14, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x15, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x16, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x17, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x18, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x19, 0x1E, 0);
    func_020660e4(arg0 + 0xA0, 0, 0x1A, 0x1E, 0);
    if (arg1 != 0) {
        func_02066c80(sp8, arg1);
        func_0206574c(arg0 + 0xA0, 0xC, -1);
        func_02065be8(arg0 + 0xA0, 0x61, 0x80, 0xA1, sp8, 1);
        temp_r3                        = M2C_FIELD(arg0, void **, 0xEC);
        M2C_FIELD(temp_r3, s32 *, 8)   = (s32) (M2C_FIELD(temp_r3, s32 *, 8) | 1);
        temp_r3_2                      = M2C_FIELD(arg0, void **, 0xF0);
        M2C_FIELD(temp_r3_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r3_2, s32 *, 8) | 1);
        func_0207a7d8(arg0, arg1);
        return;
    }
    temp_r1                        = M2C_FIELD(arg0, void **, 0xEC);
    M2C_FIELD(temp_r1, s32 *, 8)   = (s32) (M2C_FIELD(temp_r1, s32 *, 8) & ~1);
    temp_r1_2                      = M2C_FIELD(arg0, void **, 0xF0);
    M2C_FIELD(temp_r1_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r1_2, s32 *, 8) & ~1);
}
