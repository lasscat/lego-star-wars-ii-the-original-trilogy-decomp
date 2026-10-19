#include "m2c.h"

s32 RTC_GetDateTimeAsync(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK RtcWaitBusy();                            /* extern */
extern M2C_UNK RTCi_Bss;
extern M2C_UNK RtcGetResultCallback;

s32 RTC_GetDateTime(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;

    temp_r0                           = RTC_GetDateTimeAsync(arg0, arg1, &RtcGetResultCallback, 0);
    M2C_FIELD(&RTCi_Bss, s32 *, 0x24) = temp_r0;
    if (temp_r0 == 0) {
        RtcWaitBusy();
    }
    return M2C_FIELD(&RTCi_Bss, s32 *, 0x24);
}
