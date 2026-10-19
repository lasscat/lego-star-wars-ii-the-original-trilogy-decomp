#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
extern s16 OSi_IsResetOccurred;

void OSi_CommonCallback(s32 arg0, s32 arg1) {
    if (((u32) ((arg1 & 0x7F00) << 8) >> 0x10) == 0x10) {
        OSi_IsResetOccurred = 1;
        return;
    }
    OS_Terminate();
}
