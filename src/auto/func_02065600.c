#include "m2c.h"

M2C_UNK func_020654bc(s32, M2C_UNK);                /* extern */
M2C_UNK func_020655d8();                            /* extern */
extern M2C_UNK data_021047fc;

void func_02065600(void *arg0, s32 arg1) {
    s32 temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0) != arg1) {
        func_020655d8(arg0);
        M2C_FIELD(arg0, s32 *, 0) = arg1;
        func_020654bc(arg1, 0);
    }
    temp_r0 = (arg1 * 0x38) + (s32) &data_021047fc;
    M2C_FIELD(arg0, s32 *, 4) = temp_r0;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r0 + 0x1C);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), u8 *, 0xE);
}
