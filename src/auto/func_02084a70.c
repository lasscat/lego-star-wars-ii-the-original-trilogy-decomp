#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK DC_FlushRange(void *, M2C_UNK);             /* extern */

void func_02084a70(void *arg0) {
    s32 var_r0;
    s32 temp_r3;
    s32 temp_r5;
    s32 var_r1;
    s32 var_r3;
    u16 hi;
    u16 lo;

    func_0205e624(arg0 + 0xD38, 0, 0x180);
    var_r0 = 0x26;
    var_r1 = 0x2600;
    do {
        temp_r5                                   = var_r1 / 96;
        temp_r3                                   = temp_r5 / 2;
        hi                                        = (u16) (temp_r3 + 0x80);
        lo                                        = (u16) (0x80 - temp_r3);
        *((s16 *) ((u8 *) arg0 + 0xD38) + var_r0) = (s16) ((lo << 8) | hi);
        var_r0 += 1;
        var_r1 += 0x100;
    } while (var_r0 < 0x60);
    var_r3 = 0x60;
    do {
        *((u16 *) ((u8 *) arg0 + 0xD38) + var_r3) = (u16) M2C_FIELD(arg0, u16 *, 0xDF6);
        var_r3 += 1;
    } while (var_r3 < 0xC0);
    DC_FlushRange(arg0 + 0xD38, 0x180);
}
