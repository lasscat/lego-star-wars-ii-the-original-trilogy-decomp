#include "m2c.h"

M2C_UNK GX_SetBankForLCDC(s32);                         /* extern */
M2C_UNK func_020ca87c();                            /* extern */
M2C_UNK MIi_CpuClearFast(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_0206291c(void) {
    GX_SetBankForLCDC(0x1FF);
    MIi_CpuClearFast(0, 0x06800000, 0xA4000);
    func_020ca87c();
}
