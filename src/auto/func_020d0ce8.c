#include "m2c.h"

s32 func_020d094c(M2C_UNK);                         /* extern */
M2C_UNK func_020d0b1c(M2C_UNK);                     /* extern */
s32 func_020d0dd8();                                /* extern */
s32 func_020d0e50();                                /* extern */
M2C_UNK func_020d0ef0();                            /* extern */

void func_020d0ce8(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_020d0dd8();
    if (temp_r0 >= arg0) {
        return;
    }
    if ((s32) (temp_r0 + func_020d0e50()) >= arg0) {
        do {

        } while (func_020d094c(0) != 0);
        if (func_020d0dd8() >= arg0) {
            return;
        }
        goto block_8;
    }
    func_020d0b1c(1);
block_8:
    func_020d0ef0();
    do {
        func_020d094c(1);
    } while (func_020d0dd8() < arg0);
}
