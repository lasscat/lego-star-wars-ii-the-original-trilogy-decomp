#include "m2c.h"

u16 func_0200c8c4(s32 arg0, s32 arg1) {
    s32 temp_ip;
    s8 temp_r3;
    void *temp_r0;

    temp_ip = (arg1 * 0x28) + arg0;
    temp_r3 = M2C_FIELD(temp_ip, s8 *, 0x1E1);
    if ((temp_r3 != -1) && (M2C_FIELD(((temp_r3 * 0x38) + arg0), u8 *, 0x3CD) != 0)) {
        temp_r0 = M2C_FIELD(temp_ip, void **, 0x1D0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, u16 *, 0xAC);
        }
    }
    return 0x276U;
}
