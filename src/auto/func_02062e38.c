#include "m2c.h"

M2C_UNK RTC_GetDateTime(s32, s32);                    /* extern */

void func_02062e38(s32 arg0) {
    RTC_GetDateTime(arg0, arg0 + 0x10);
}
