#include "m2c.h"

s32 func_020d094c(M2C_UNK);                         /* extern */
M2C_UNK func_020d0b1c(M2C_UNK);                     /* extern */
s32 func_020d0e50();                                /* extern */
M2C_UNK func_020d0ef0();                            /* extern */
s32 func_020d0f18();                                /* extern */
s32 func_020d0f60();                                /* extern */

s32 func_020d0a5c(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    if (func_020d0f60() == 0) {
        return 0;
    }
    temp_r0_3 = func_020d0f18();
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    if (!(arg0 & 1)) {
        return 0;
    }
    if (func_020d0e50() > 0) {
        do {

        } while (func_020d094c(0) != 0);
        temp_r0_2 = func_020d0f18();
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        goto block_12;
    }
    func_020d0b1c(1);
block_12:
    func_020d0ef0();
    do {
        func_020d094c(1);
        temp_r0 = func_020d0f18();
    } while (temp_r0 == 0);
    return temp_r0;
}
