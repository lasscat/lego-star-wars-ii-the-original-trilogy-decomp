#include "m2c.h"

M2C_UNK func_020c33a8(s32, s32, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_020c36ec(s32, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 func_020ca904();                                /* extern */
s32 func_020ca91c();                                /* extern */
extern M2C_UNK data_0210a30c;
extern M2C_UNK data_0210ab0c;

void func_020ac624(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;

    temp_r5                      = func_020ca904();
    temp_r4                      = func_020ca91c();
    M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
    func_020c33a8(temp_r5, M2C_FIELD(arg0, s32 *, 0x4C), &data_0210a30c, 0x800, 1);
    func_020c36ec(temp_r4, &data_0210ab0c, 0x800, 1);
}
