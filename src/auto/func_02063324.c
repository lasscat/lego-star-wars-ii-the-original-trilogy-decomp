#include "m2c.h"

M2C_UNK func_020630b8(u32);                         /* extern */
s32 func_020633dc(u32);                             /* extern */
s32 func_02063418(u32);                             /* extern */
M2C_UNK func_02062fe0(u32);                         /* extern */
extern M2C_UNK data_02104364;

u32 func_02063324(void) {
    u32 var_r7;
    u32 var_r8;
    u8 *var_r9;
    u8 *var_r10;
    s32 temp_r1;

    var_r7  = 0;
    var_r9  = (u8 *) &data_02104364;
    var_r8  = 0;
    var_r10 = var_r9;
    for (; var_r8 < 3U; var_r8++) {
        if (func_02063418(var_r8) != 0) {
            if (func_020633dc(var_r8) != 0) {
                func_020630b8(var_r8);
                temp_r1 = M2C_FIELD(var_r9, s32 *, 0x24);
                if ((temp_r1 != 0xFDDB597D) && (temp_r1 != 0x88CC44FF)) {
                    M2C_FIELD(var_r10, s8 *, 0x48) = 0;
                    M2C_FIELD(var_r10, s8 *, 0x4B) = 1;
                }
                if (M2C_FIELD(var_r9, s32 *, 0x24) == 0xFDDB597D) {
                    M2C_FIELD(var_r10, s8 *, 0x48) = 0;
                }
            } else {
                func_02062fe0(var_r8);
                var_r7                         = 8;
                M2C_FIELD(var_r10, s8 *, 0x4B) = 1;
            }
        } else {
            return 1U;
        }
        var_r9 += 0xC;
        var_r10 += 1;
    }
    return var_r7;
}
