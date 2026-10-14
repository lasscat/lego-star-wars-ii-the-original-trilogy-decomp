#include "m2c.h"

M2C_UNK func_020b37c0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b3998(void *, M2C_UNK);             /* extern */
s8 func_020b9284();                                 /* extern */

void func_020b3718(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s8 *, 4)     = 1;
    M2C_FIELD(arg0, s8 *, 0x3F)  = 0;
    M2C_FIELD(arg0, s8 *, 0x3E)  = 0;
    M2C_FIELD(arg0, s8 *, 5)     = 0;
    M2C_FIELD(arg0, s8 *, 3)     = 0;
    M2C_FIELD(arg0, s8 *, 6)     = 0;
    M2C_FIELD(arg0, s8 *, 0x16)  = func_020b9284();
    func_020b37c0(arg0, 0);
    func_020b3998(arg0, 0);
    M2C_FIELD(arg0, s8 *, 0x11) = 0;
}
