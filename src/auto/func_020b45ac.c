#include "m2c.h"

M2C_UNK func_020b82e8(u8);                          /* extern */
extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;
extern M2C_UNK data_0210dc2f;

void func_020b45ac(s32 arg0) {
    s8 *var_r5;
    s32 var_r4;
    s32 var_r6;
    void *temp_r0;

    if (arg0 == 4) {
        var_r4 = 0;
        do {
            func_020b45ac(var_r4);
            var_r4 += 1;
        } while (var_r4 < 3);
        return;
    }
    temp_r0 = *((M2C_UNK *) ((s8 *) &data_0210dafc + (arg0 * 4)));
    if (temp_r0 == NULL) {
        return;
    }
    var_r5        = (s8 *) &data_0210dc2f;
    data_0210daf0 = temp_r0;
    var_r6        = 0xF;
    do {
        if (M2C_FIELD(data_0210daf0, u8 *, 0x39) == M2C_FIELD(var_r5, u8 *, 4)) {
            func_020b82e8((u8) var_r6);
        }
        var_r5 -= 1;
        var_r6 -= 1;
    } while ((s32) var_r6 >= 0);
}
