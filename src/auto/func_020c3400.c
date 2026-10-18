/* Reconstructed from USA ARM9 at 0x020c3400 (144 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020c3110(M2C_UNK *, M2C_UNK *, s32 *, u32); /* extern */
extern M2C_UNK data_02112628;
extern M2C_UNK data_0211262c;
extern M2C_UNK data_02112630;

s32 func_020c3400(s32 arg0, s32 arg1) {
    s32 sp0;
    s32 var_r0;
    u32 var_r5;

    if (arg0 == 0) {
        var_r5 = 0x10;
    } else {
        var_r5 = (arg0 + 0xF) & ~0xF;
    }
    if (var_r5 >= 0x7FFF0U) {
        return 0;
    }
    if (arg1 != 0) {
        var_r0 = func_020c3110(&data_0211262c, &data_02112630, &sp0, var_r5);
    } else {
        var_r0 = func_020c3110(&data_02112628, &data_02112630, &sp0, var_r5);
    }
    if (var_r0 == 0) {
        return 0;
    }
    return ((var_r5 >> 4) << 0x10) | ((u32) (sp0 << 0xD) >> 0x10) | (arg1 << 0x1F);
}
