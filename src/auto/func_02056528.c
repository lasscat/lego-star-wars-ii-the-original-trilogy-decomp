#include "m2c.h"

s32 FX_Div(s32, M2C_UNK);                    /* extern */
extern s32 data_02101b70;

void func_02056528(s32 arg0, u8 *arg1) {
    data_02101b70 = FX_Div(*arg1 << 0xC, 0x64000);
}
