#include "m2c.h"

M2C_UNK func_0201812c(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_02018278(M2C_UNK *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_0202cb44(s32);                             /* extern */
M2C_UNK func_020370ec(M2C_UNK *);                   /* extern */
M2C_UNK func_02037128(s32, s32, M2C_UNK *);         /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02062b3c(M2C_UNK);                         /* extern */

void func_0202e644(s32 arg0) {
    M2C_UNK sp24[3];
    M2C_UNK spC[6];
    s32 temp_r0;

    func_02018278(sp24, arg0, func_0202cb44(arg0 + 0x5E0), 0x46, 0x46, 0xF, 0x28);
    func_0201812c(arg0, sp24, 0);
    func_020370ec(spC);
    M2C_FIELD(spC, s16 *, 0) = 0x1D;
    if (func_02062b3c(0x32) != 0) {
        M2C_FIELD(spC, s16 *, 0) = 0x1E;
    }
    M2C_FIELD(spC, s8 *, 0xC) = 0;
    M2C_FIELD(spC, s8 *, 0xE) = 1;
    M2C_FIELD(spC, s8 *, 0xD) = 0;
    temp_r0                   = func_0205e80c(0x28, 3, 4);
    if (temp_r0 == 0) {
        return;
    }
    func_02037128(temp_r0, arg0, spC);
}
