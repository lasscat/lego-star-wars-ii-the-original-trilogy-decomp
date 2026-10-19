#include "m2c.h"
void *func_0208dad8(u16);
extern M2C_UNK data_020f6bc4;
s32 func_020062b4(void *arg0) {
    s32 var_r4 = 0;
    s32 var_r5 = 0;
    do {
        if (((u16 *) ((s8 *) arg0 + 0x6E8))[var_r5] != 0xFA) {
            var_r4 |= M2C_FIELD(func_0208dad8(((u16 *) ((s8 *) arg0 + 0x6E8))[var_r5]), s32 *, 0x10);
        }
        var_r5++;
    } while (var_r5 < 5);
    {
        u8 temp_r2 = M2C_FIELD(arg0, u8 *, 0x6C3);
        if (temp_r2 != 0x28) {
            var_r4 |= *((M2C_UNK *) ((s8 *) &data_020f6bc4 + (temp_r2 * 0x24)));
        }
    }
    return var_r4;
}
