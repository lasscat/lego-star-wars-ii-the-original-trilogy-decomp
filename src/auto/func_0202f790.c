#include "m2c.h"

s32 func_02031a5c(s32, M2C_UNK, u32);               /* extern */
s32 func_020341f4(s32, M2C_UNK, u32);               /* extern */
s32 func_02044e54(s32, M2C_UNK, u32);               /* extern */
s32 func_0204890c(s32, M2C_UNK, u32);               /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s32 func_0202f790(M2C_UNK arg0, u32 arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;

    switch (arg1) {
        case 0:
            temp_r0 = func_0205e80c(0x14, 1, 4);
            if (temp_r0 == 0) {
                return temp_r0;
            }
            return func_02044e54(temp_r0, arg0, arg1);
        case 1:
            temp_r0_2 = func_0205e80c(0x38, 1, 4);
            if (temp_r0_2 == 0) {
                return temp_r0_2;
            }
            return func_0204890c(temp_r0_2, arg0, arg1);
        case 3:
            temp_r0_3 = func_0205e80c(0x64, 1, 4);
            if (temp_r0_3 == 0) {
                return temp_r0_3;
            }
            return func_020341f4(temp_r0_3, arg0, arg1);
        case 4:
            temp_r0_4 = func_0205e80c(0x34, 1, 4);
            if (temp_r0_4 == 0) {
                return temp_r0_4;
            }
            return func_02031a5c(temp_r0_4, arg0, arg1);
        default:
        case 2:
            return 0;
    }
}
