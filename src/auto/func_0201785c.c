#include "m2c.h"

void *func_02017800(void *, M2C_UNK);               /* extern */
s32 func_02017820(void *, void *);                  /* extern */

s32 func_0201785c(void *arg0) {
    s32 var_r3;
    u16 temp_r2;
    u32 var_lr;
    u32 var_r5;
    u8 temp_r3;
    void *temp_r0;

    temp_r2 = M2C_FIELD(arg0, u16 *, 0x212);
    if ((temp_r2 == 0x165) || (temp_r2 == 8) || (temp_r2 == 0x4B)) {
        return 0;
    }
    temp_r0 = func_02017800(arg0, 0);
    if (temp_r0 != NULL) {
        if (M2C_FIELD(temp_r0, s8 *, 0x1D8) != M2C_FIELD(temp_r0, u8 *, 0x1DC)) {
            var_r5 = 0;
            var_lr = 0;
            do {
                temp_r3 = ((u8 *) temp_r0)[0x1DE + var_lr * 2];
                if ((temp_r3 == 0xFF) || (((u8 *) temp_r0)[0x1DF + var_lr * 2] == 0)) {
                    var_r3 = 0;
                } else {
                    var_r3 = 1;
                }
                if (var_r3 != 0) {
                    var_r5 += 1;
                }
                var_lr += 1;
            } while (var_lr < 0x19U);
            if (var_r5 > 1U) {
                return func_02017820(temp_r0, arg0);
            }
        }
    }
    return 0;
}
