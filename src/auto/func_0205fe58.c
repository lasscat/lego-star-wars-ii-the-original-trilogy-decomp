#include "m2c.h"

M2C_UNK func_0205ecc4(); /* extern */
M2C_UNK func_02060184();  /* extern */
extern s32 data_027e02a4;

void func_0205fe58(s32 arg0, u32 arg1, void *arg2, s32 arg3) {
    void *temp_r3;

    switch (arg1) {
        case 4:
        case 6:
            if (arg3 == 1) {
                func_0205ecc4(arg0, M2C_FIELD(arg2, s32 *, 0), data_027e02a4, 0, 0, 0);
                return;
            }
            if (arg3 == 3) {
                func_0205ecc4(arg0, M2C_FIELD(arg2, s32 *, 0), data_027e02a4, M2C_FIELD(arg2, s32 *, 4),
                              M2C_FIELD(arg2, s32 *, 8), 0);
                return;
            }
            func_0205ecc4(arg0, M2C_FIELD(arg2, s32 *, 0), data_027e02a4, M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 8),
                          M2C_FIELD(arg2, s32 *, 0xC));
            return;
        case 13:
            if (arg3 != 1) {
                return;
            }
            func_0205ecc4(arg0, 4, data_027e02a4, 0, M2C_FIELD(arg2, s32 *, 0), 0);
            return;
        case 9:
            func_02060184(arg0, data_027e02a4, M2C_FIELD(arg2, s32 *, 0), arg3 - 1, arg2 + 4);
            return;
        case 2:
            temp_r3 = arg0 + (data_027e02a4 << 5);
            func_0205ecc4(arg0, M2C_FIELD(temp_r3, s32 *, 8), data_027e02a4, M2C_FIELD(temp_r3, s32 *, 0xC),
                          M2C_FIELD(temp_r3, s32 *, 0x10), M2C_FIELD(temp_r3, s32 *, 0x14));
            return;
        default:
            return;
    }
}
