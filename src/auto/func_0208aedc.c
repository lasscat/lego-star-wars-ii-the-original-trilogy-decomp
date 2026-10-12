#include "m2c.h"

M2C_UNK func_0206672c(s32, M2C_UNK *);              /* extern */
s32 func_0208ad84();                                /* extern */
M2C_UNK func_0208adb8(M2C_UNK, s32, M2C_UNK *);     /* extern */

void func_0208aedc(M2C_UNK arg0, s32 arg1) {
    u8 sp0[64];
    s32 temp_r4;

    if (arg1 == 0) {
        return;
    }
    temp_r4 = func_0208ad84();
    func_0206672c(arg1, sp0);
    func_0208adb8(arg0, temp_r4, sp0);
}
