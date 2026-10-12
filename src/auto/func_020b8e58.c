#include "m2c.h"

M2C_UNK func_020b3c1c();                            /* extern */
s32 func_020d094c(M2C_UNK);                         /* extern */
M2C_UNK func_020d0b1c(M2C_UNK);                     /* extern */
M2C_UNK func_020d2f90(M2C_UNK *);                   /* extern */
M2C_UNK func_020d2fe4(M2C_UNK *);                   /* extern */
extern s32 data_0210daf0;
extern M2C_UNK data_0210db14;

void func_020b8e58(void) {
    u8 sp0[28];
    s32 temp_r5;

    if (M2C_FIELD(&data_0210db14, u8 *, 0xA) & 0x80) {
        M2C_FIELD(&data_0210db14, s8 *, 0xB) = 1;
        return;
    }
    temp_r5 = data_0210daf0;
    func_020d2f90(sp0);
    do {

    } while (func_020d094c(0) != 0);
    func_020b3c1c();
    func_020d0b1c(2);
    func_020d2fe4(sp0);
    data_0210daf0 = temp_r5;
}
