#include "m2c.h"

M2C_UNK func_0209f2cc(void *);                      /* extern */
M2C_UNK func_0209f8d4(void *);                      /* extern */
M2C_UNK NNS_G3dRenderObjRemoveAnmObj(void *, s32);                      /* extern */

u32 func_0209f5d0(s8 *arg0) {
    s32 var_r5;
    s32 slot;
    u32 var_r0;
    s8 *var_r6;
    u16 temp_r0;

    var_r0 = (u32) (M2C_FIELD(arg0, u16 *, 0xB2) << 0x1F) >> 0x1F;
    if (var_r0 == 0) {
        return var_r0;
    }
    var_r6 = arg0 + 0x74;
    var_r5 = 0;
    do {
        slot = ((s32 *) (arg0 + 0x74))[var_r5 * 2];
        if (slot != 0) {
            NNS_G3dRenderObjRemoveAnmObj(arg0 + 0x20, slot);
            func_0209f2cc(var_r6);
        }
        var_r5 += 1;
        var_r6 += 8;
    } while (var_r5 < 5);
    func_0209f8d4(arg0);
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    temp_r0                      = M2C_FIELD(arg0, u16 *, 0xB2) | 2;
    M2C_FIELD(arg0, u16 *, 0xB2) = temp_r0;
    return (u32) temp_r0;
}
