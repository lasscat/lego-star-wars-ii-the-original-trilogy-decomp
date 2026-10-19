/* Reconstructed from USA ARM9 at 0x020c3740 (204 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 NNSi_GfdAllocLnkVramAligned(M2C_UNK *, M2C_UNK *, s32 *, u32, s32); /* extern */
M2C_UNK NNSi_GfdFreeLnkVram(M2C_UNK *, M2C_UNK *, s32, u32); /* extern */
extern M2C_UNK data_02112644;
extern M2C_UNK data_02112648;

s32 NNS_GfdAllocLnkPlttVram(s32 arg0, s32 arg1) {
    s32 sp4;
    s32 var_r0;
    u32 var_r4;

    if (arg0 == 0) {
        var_r4 = 8;
    } else {
        var_r4 = (arg0 + 7) & ~7;
    }
    if (var_r4 >= 0x7FFF8U) {
        return 0;
    }
    if (arg1 != 0) {
        var_r0 = NNSi_GfdAllocLnkVramAligned(&data_02112644, &data_02112648, &sp4, var_r4, 8);
        if ((u32) (sp4 + var_r4) > 0x10000U) {
            NNSi_GfdFreeLnkVram(&data_02112644, &data_02112648, sp4, var_r4);
            return 0;
        }
        goto block_9;
    }
    var_r0 = NNSi_GfdAllocLnkVramAligned(&data_02112644, &data_02112648, &sp4, var_r4, 0x10);
block_9:
    if (var_r0 == 0) {
        return 0;
    }
    return ((var_r4 >> 3) << 0x10) | ((u32) (sp4 << 0xD) >> 0x10);
}
