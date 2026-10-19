/* Reconstructed from USA ARM9 at 0x020adca4 (212 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *);                   /* extern */
M2C_UNK func_020de858(void *, s32, M2C_UNK);        /* extern */
s32 func_020de930(void *, s32, M2C_UNK);            /* extern */
extern M2C_UNK data_02100030;
extern M2C_UNK data_02100064;
extern M2C_UNK data_0210bf40;
extern M2C_UNK data_0210c000;

void func_020adca4(s32 arg0) {
    s8 *var_r1;
    s32 temp_r5;
    s32 var_r2;
    s32 var_r6;
    s8 *var_r7;

    var_r7 = (s8 *) &data_0210bf40;
    var_r6 = 0;
loop_1:
    if ((func_020de930(var_r7 + 4, arg0 + 4, 0xC) == 0) && (M2C_FIELD(var_r7, s32 *, 0xC0) != 0)) {
        *((M2C_UNK *) ((s8 *) &data_0210c000 + (var_r6 * 0xC4))) = 0x5A;
        func_020ad528(&data_02100030);
        return;
    }
    var_r6 += 1;
    var_r7 += 0xC4;
    if (var_r6 >= 0x10) {
        var_r1 = (s8 *) &data_0210bf40;
        var_r2 = 0;
    loop_6:
        if (M2C_FIELD(var_r1, s32 *, 0xC0) == 0) {
            temp_r5 = var_r2 * 0xC4;
            func_020de858((M2C_UNK *) ((s8 *) &data_0210bf40 + temp_r5), arg0, 0xC0);
            *((M2C_UNK *) ((s8 *) &data_0210c000 + temp_r5)) = 0x5A;
        } else {
            var_r2 += 1;
            var_r1 += 0xC4;
            if (var_r2 < 0x10) {
                goto loop_6;
            }
        }
        func_020ad528(&data_02100064);
        return;
    }
    goto loop_1;
}
