#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
s32 WM_PowerOn(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020adfdc;

s32 func_020adf74(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x31;
    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    temp_r0                                = WM_PowerOn(&func_020adfdc);
    if (temp_r0 == 0) {
        return 1;
    }
    if (temp_r0 != 2) {
        func_020ad8b4();
        return 0;
    }
    func_020addf0(0x32);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        return 1;
    }
    return 0;
}
