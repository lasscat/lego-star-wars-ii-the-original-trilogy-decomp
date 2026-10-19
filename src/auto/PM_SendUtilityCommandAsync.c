#include "m2c.h"

s32 func_020d3a08();                                /* extern */
M2C_UNK PMi_SendPxiData(s32);                         /* extern */
extern M2C_UNK data_0211748c;

s32 PM_SendUtilityCommandAsync(u32 arg0, s32 arg1, s32 arg2) {
    if (func_020d3a08() == 0) {
        return 1;
    }
    M2C_FIELD(&data_0211748c, s32 *, 0x1C) = arg1;
    M2C_FIELD(&data_0211748c, s32 *, 0x20) = arg2;
    PMi_SendPxiData((u8) (arg0 >> 0x10) | 0x6300 | 0x2000000);
    PMi_SendPxiData(0x01010000 | (u16) arg0);
    return 0;
}
