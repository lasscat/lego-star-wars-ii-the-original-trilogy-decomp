#include "m2c.h"

M2C_UNK RTC_GetTime(s32);                         /* extern */

void func_02062e1c(s32 arg0) {
    RTC_GetTime(arg0 + 0x10);
}
