#include "engine.h"
#include "m2c.h"

M2C_UNK OS_DisableInterrupts(void);
void OS_RestoreInterrupts(M2C_UNK);
M2C_UNK RTCi_ReadRawDateTimeAsync(void);

extern M2C_UNK RTCi_Bss;

s32 RTC_GetDateTimeAsync(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;

    temp_r0 = OS_DisableInterrupts();
    if (M2C_FIELD(&RTCi_Bss, s32 *, 4) != 0) {
        OS_RestoreInterrupts(temp_r0);
        return 1;
    }
    M2C_FIELD(&RTCi_Bss, s32 *, 4) = 1;
    OS_RestoreInterrupts(temp_r0);
    M2C_FIELD(&RTCi_Bss, s32 *, 0x18) = 2;
    M2C_FIELD(&RTCi_Bss, s32 *, 0x1C) = 0;
    M2C_FIELD(&RTCi_Bss, s32 *, 0xC)  = arg0;
    M2C_FIELD(&RTCi_Bss, s32 *, 0x10) = arg1;
    M2C_FIELD(&RTCi_Bss, s32 *, 8)    = arg2;
    M2C_FIELD(&RTCi_Bss, s32 *, 0x14) = arg3;
    if (RTCi_ReadRawDateTimeAsync() != 0) {
        return 0;
    }
    return 3;
}
