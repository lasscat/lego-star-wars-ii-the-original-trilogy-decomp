#include "m2c.h"

extern M2C_UNK data_02108d84;
extern const u32 data_020f86f8[];

void func_02086f98(void) {
    s32 y;
    s32 month;
    s32 idx;
    s32 days;

    y     = M2C_FIELD(&data_02108d84, s32 *, 0x4B8) + 2000;
    days  = M2C_FIELD(&data_02108d84, s32 *, 0x4C0);
    month = M2C_FIELD(&data_02108d84, s32 *, 0x4BC);
    y -= 2000;
    idx = month - 1;
    days += y * 365 + (y >> 2);
    days += data_020f86f8[idx];
    days += ((y & 3) != 0 || month > 2);
    M2C_FIELD(&data_02108d84, s32 *, 0x4D4) =
        (days - 1) * 86400 + 0x80000000 +
        (M2C_FIELD(&data_02108d84, s32 *, 0x4D0) +
         (M2C_FIELD(&data_02108d84, s32 *, 0x4CC) * 60 + M2C_FIELD(&data_02108d84, s32 *, 0x4C8) * 3600));
}
