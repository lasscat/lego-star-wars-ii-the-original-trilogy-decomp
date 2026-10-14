#include "m2c.h"

M2C_UNK func_020861bc(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_02086234(M2C_UNK *, u16, u8);          /* extern */
s32 func_020867ec(M2C_UNK *, u16);                  /* extern */
M2C_UNK func_02086810(M2C_UNK *, u16, s32);         /* extern */
extern M2C_UNK data_02104d90;

void func_02089a78(void *arg0) {
    s32 var_r2;
    s32 var_r8;
    u16 var_r6;
    u16 var_r7;
    void *temp_r2;

    if (M2C_FIELD(arg0, s8 *, 0x290A) == -1) {
        return;
    }
    var_r8 = 0;
    do {
        if (var_r8 != 0xB) {
            if (M2C_FIELD((arg0 + ((var_r8 >> 5) * 4)), s32 *, 0x2870) & (1 << (var_r8 & 0x1F))) {
                var_r2 = 1;
            } else {
                var_r2 = 0;
            }
            func_020861bc(&data_02104d90, var_r8, var_r2);
        }
        var_r8 = (s32) (u16) (var_r8 + 1);
    } while ((u32) var_r8 < 0x39U);
    var_r6 = 0;
    do {
        func_02086234(&data_02104d90, var_r6, M2C_FIELD((arg0 + var_r6), u8 *, 0x2878));
        var_r6 += 1;
    } while ((u32) var_r6 < 0x39U);
    var_r7 = 0;
    do {
        temp_r2 = arg0 + var_r7;
        if (((M2C_FIELD(temp_r2, u8 *, 0x28B1) != 0) && (func_020867ec(&data_02104d90, var_r7) == 0)) ||
            ((M2C_FIELD(temp_r2, u8 *, 0x28B1) == 0) && (func_020867ec(&data_02104d90, var_r7) != 0))) {
            func_02086810(&data_02104d90, var_r7, 0);
        }
        var_r7 += 1;
    } while ((u32) var_r7 < 0x12U);
}
