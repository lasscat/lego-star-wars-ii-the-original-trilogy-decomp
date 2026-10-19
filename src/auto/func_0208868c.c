#include "m2c.h"

s32 func_02088798(void *, s32);                     /* extern */
extern M2C_UNK data_021044a4;

s32 func_0208868c(void *arg0) {
    s32 temp_r0;
    s32 var_r4;
    u16 temp_r5;
    u16 temp_r6;
    u8 temp_r0_2;

    if (M2C_FIELD(arg0, u16 *, 6) == 4) {
        return 4;
    }
    if (((u32) (M2C_FIELD(&data_021044a4, u8 *, 0) << 0x1B) >> 0x1F) != 0) {
        temp_r5 = M2C_FIELD(&data_021044a4, u16 *, 0x2A);
        temp_r6 = M2C_FIELD(&data_021044a4, u16 *, 0x2C);
        var_r4  = 0;
        do {
            temp_r0_2 = M2C_FIELD((arg0 + var_r4), u8 *, 0x11);
            if (((u32) temp_r5 >= (u32) (u16) (temp_r0_2 * 8)) && ((s32) temp_r5 < (s32) ((u16) (temp_r0_2 * 8) + 0x30)) &&
                ((u32) temp_r6 >= 0x90U) && ((s32) temp_r6 < 0xB8)) {
                temp_r0 = func_02088798(arg0, var_r4);
                if ((temp_r0 != 4) && (temp_r0 != M2C_FIELD(arg0, u16 *, 6))) {
                    M2C_FIELD(arg0, s16 *, 8)   = (s16) temp_r0;
                    M2C_FIELD(arg0, s16 *, 0xA) = (s16) var_r4;
                    return temp_r0;
                }
            }
            var_r4 += 1;
        } while (var_r4 < 3);
    }
    return 4;
}
