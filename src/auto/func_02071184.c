#include "m2c.h"

M2C_UNK func_0206574c(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_02065be8(void *, s32, s32, s32, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
extern M2C_UNK data_020edf34;
extern M2C_UNK data_020edf44;
extern M2C_UNK data_020edf54;

void func_02071184(void *arg0) {
    s32 var_r8;
    u8 var_r9;

    func_0206574c(arg0 + 0x5C, 6, -2);
    var_r8 = func_02065be8(arg0 + 0x5C, 1, 0x7F, 0xC, func_02066708(0x79), 1);
    func_0206574c(arg0 + 0x5C, 0, -2);
    var_r9 = 0;
    do {
        if (var_r9 == M2C_FIELD(arg0, s32 *, 0x90)) {
            func_0206574c(arg0 + 0x5C, 3, -2);
        } else {
            func_0206574c(arg0 + 0x5C, 0, -2);
        }
        var_r8 = func_02065be8(arg0 + 0x5C, var_r8, *((M2C_UNK *)((s8 *)&data_020edf54 + (var_r9 * 4))), *((M2C_UNK *)((s8 *)&data_020edf44 + (var_r9 * 4))), func_02066708(*((M2C_UNK *)((s8 *)&data_020edf34 + (var_r9 * 4)))), 0);
        var_r9 += 1;
    } while ((u32) var_r9 < 4U);
}
