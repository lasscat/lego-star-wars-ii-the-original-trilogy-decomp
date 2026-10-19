#include "m2c.h"

M2C_UNK TP_RequestAutoSamplingStartAsync(M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK TP_WaitBusy(M2C_UNK);                     /* extern */
u32 func_020d39f4(M2C_UNK);                         /* extern */

u32 func_0206463c(u8 *arg0) {
    u32 temp_r0;
    u32 var_r0;

    temp_r0 = (u32) (*arg0 << 0x1E) >> 0x1F;
    if (temp_r0 != 0) {
        return temp_r0;
    }
    TP_RequestAutoSamplingStartAsync(0x20, 4, arg0 + 2, 5);
    TP_WaitBusy(2);
    var_r0 = func_020d39f4(2);
    if (var_r0 == 0) {
        var_r0 = *arg0 | 2;
        *arg0  = (u8) var_r0;
    }
    return var_r0;
}
