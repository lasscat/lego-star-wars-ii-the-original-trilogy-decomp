/* Reconstructed from USA ARM9 at 0x020d9c88 (156 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK MI_CpuCopy8(void *, void *, M2C_UNK);     /* extern */

void MB_ReadMultiBootParentBssDesc(void *arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 var_r0_2;
    s32 var_r3;
    void *var_r0;

    if (*(u16 *) 0x027FFC40 == 2) {
        var_r0 = (u16 *) 0x027FFC40 + 1;
    } else {
        var_r0 = NULL;
    }
    MI_CpuCopy8(var_r0, arg0, 0x3C);
    M2C_FIELD(arg0, s16 *, 0x3C) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x40) = 1;
    var_r3                       = 0;
    M2C_FIELD(arg0, s8 *, 0x42)  = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, u16 *, 0xC) | (M2C_FIELD(arg0, u16 *, 0xE) << 0x10));
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
    M2C_FIELD(arg0, s8 *, 0x4A)  = 0;
    if (arg4 != 0) {
        var_r3 = 8;
    }
    if (arg3 != 0) {
        var_r0_2 = 4;
    } else {
        var_r0_2 = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x4C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x4E) = arg2;
    M2C_FIELD(arg0, s8 *, 0x4B)  = (s8) (var_r0_2 | var_r3 | 1);
}
