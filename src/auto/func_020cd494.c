#include "m2c.h"

M2C_UNK func_020ccf68(s32, void *);                 /* extern */
M2C_UNK func_020cd59c();                            /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
extern M2C_UNK data_02115424;

void func_020cd494(s32 arg0) {
    s32 temp_r4;
    void *temp_r5;

    temp_r4 = func_020ce804();
    temp_r5 = *M2C_FIELD(&data_02115424, void ***, 8);
    if (arg0 != 0) {
        M2C_FIELD(temp_r5, s32 *, 0x78) = arg0;
        func_020ccf68(arg0, temp_r5);
    }
    M2C_FIELD(temp_r5, s32 *, 0x64) = 0;
    func_020cd59c();
    func_020ce818(temp_r4);
}
