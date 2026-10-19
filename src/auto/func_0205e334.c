/* Reconstructed from USA ARM9 at 0x0205e334 (156 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e3f4(void *, u8, s32);              /* extern */
s32 func_0205e818(s32, u8, M2C_UNK);                /* extern */
s32 func_020e4600(s32, s32, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_0205ded0;
extern M2C_UNK func_0205e3d0;

void func_0205e334(void *arg0) {
    s32 var_r0;
    u16 var_r4;

    var_r4 = M2C_FIELD(arg0, u16 *, 0x1C);
    if (var_r4 == 0) {
        var_r4 = (u16) M2C_FIELD(arg0, u8 *, 0x21);
    }
    var_r0 = func_0205e818((var_r4 * 0x18) + 8, M2C_FIELD(arg0, u8 *, 0x20), 4);
    if (var_r0 != 0) {
        var_r0 = func_020e4600(var_r0, var_r4, 0x18, 8, &func_0205e3d0, &func_0205ded0);
    }
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0x22) * 4)), s32 *, 0x24) = var_r0;
    func_0205e3f4(arg0, M2C_FIELD(arg0, u8 *, 0x22), var_r4);
    M2C_FIELD(arg0, u16 *, 0x1C) = (u16) (M2C_FIELD(arg0, u16 *, 0x1C) + var_r4);
    M2C_FIELD(arg0, u8 *, 0x22)  = (u8) (M2C_FIELD(arg0, u8 *, 0x22) + 1);
}
