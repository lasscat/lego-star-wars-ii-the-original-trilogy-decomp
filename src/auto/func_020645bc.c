#include "m2c.h"

u32 func_0206463c(u8 *);                            /* extern */
s32 TP_GetUserInfo(s16 *);                           /* extern */
M2C_UNK func_020d33bc(s16 *);                       /* extern */

u32 func_020645bc(u8 *arg0) {
    s16 sp[4];
    u32 temp_r0;

    temp_r0 = (u32) (*arg0 << 0x1F) >> 0x1F;
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (TP_GetUserInfo(sp) == 0) {
        sp[0] = 0x3B6;
        sp[1] = 0x331;
        sp[2] = 0xE35;
        sp[3] = 0x12E6;
    }
    func_020d33bc(sp);
    *arg0 = (*arg0 & ~1) | 1;
    return func_0206463c(arg0);
}
