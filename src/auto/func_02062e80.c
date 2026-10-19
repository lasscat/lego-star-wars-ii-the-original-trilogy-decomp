#include "m2c.h"

M2C_UNK RTC_GetDateTimeAsync(s32, s32, M2C_UNK, s32);      /* extern */

void func_02062e80(s32 arg0, M2C_UNK arg1) {
    RTC_GetDateTimeAsync(arg0, arg0 + 0x10, arg1, arg0);
}
