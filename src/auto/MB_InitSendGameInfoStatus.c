#include "m2c.h"

M2C_UNK MBi_ClearSendStatus();                            /* extern */
extern M2C_UNK sUnlockFunc;

void MB_InitSendGameInfoStatus(void) {
    M2C_FIELD(&sUnlockFunc, s32 *, 0x18) = 0;
    M2C_FIELD(&sUnlockFunc, s32 *, 0x1C) = 0;
    M2C_FIELD(&sUnlockFunc, s8 *, 0x24)  = 1;
    M2C_FIELD(&sUnlockFunc, s32 *, 0x14) = 0;
    MBi_ClearSendStatus();
}
