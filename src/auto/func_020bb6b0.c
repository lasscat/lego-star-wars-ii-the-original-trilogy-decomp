#include "m2c.h"

M2C_UNK func_020bb488(u8, s32);
s32 func_020bb918(M2C_UNK);
M2C_UNK SND_StopTimer(s32, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK SND_WaitForFreeCommand(M2C_UNK);
s32 SND_GetCurrentCommandTag();
extern M2C_UNK data_0210dc48;

void func_020bb6b0(u32 arg0, s32 arg1) {
    s32 temp_r4;

    if (arg0 == 0xFFFFFFFFU) {
        return;
    }
    temp_r4 = ((arg0 & 0xFF) * 0x1C) + (s32) &data_0210dc48;

    if (func_020bb918(arg0) != 0) {
        if (M2C_FIELD(temp_r4, u8 *, 1) == 3) {
            SND_WaitForFreeCommand(1);
            SND_StopTimer(1 << M2C_FIELD(temp_r4, u8 *, 2), 0, 0, 0);
            M2C_FIELD(temp_r4, s32 *, 0x18) = SND_GetCurrentCommandTag();
            func_020bb488(M2C_FIELD(temp_r4, u8 *, 2), (arg0 & 0xFF) | 0x20);
        }
        M2C_FIELD(temp_r4, u8 *, 1) = (u8) (arg1 + 1);
        return;
    }
    if ((arg1 == 1) && (M2C_FIELD(temp_r4, u8 *, 1) == 0)) {
        M2C_FIELD(temp_r4, u8 *, 1) = 1U;
    }
}
