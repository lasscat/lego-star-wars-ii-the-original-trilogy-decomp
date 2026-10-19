#include "m2c.h"

M2C_UNK func_0201b318(s32, u8);                     /* extern */
M2C_UNK func_02072f94();                            /* extern */
M2C_UNK func_020734b0();                            /* extern */
s32 FX_Div(s32, s32);                        /* extern */
extern void **data_021092f4;

void func_020732e8(void *arg0) {
    s32 var_r0;
    u8 var_r1;

    func_020734b0();
    if (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) == 0) {
        var_r0 = FX_Div(M2C_FIELD(arg0, u16 *, 0xE0AA) << 0xC, M2C_FIELD(arg0, s32 *, 0xA4) << 0xC);
    } else {
        var_r0 = FX_Div(M2C_FIELD(arg0, u16 *, 0xE0AC) << 0xC, M2C_FIELD(arg0, s32 *, 0xA4) << 0xC);
    }
    var_r1 = (u8) ((s32) (var_r0 * 0x15) >> 0xC);
    if ((u32) var_r1 >= 0x15U) {
        var_r1 = 0x14;
    }
    func_0201b318(M2C_FIELD(arg0, s32 *, 0x94), var_r1);
    func_02072f94();
}
