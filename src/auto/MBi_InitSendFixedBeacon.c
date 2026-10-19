#include "m2c.h"

extern M2C_UNK sUnlockFunc;

void MBi_InitSendFixedBeacon(void) {
    u8 *p;

    if (M2C_FIELD(&sUnlockFunc, u8 *, 0x24) != 2) {
        return;
    }
    p = M2C_FIELD(&sUnlockFunc, u8 **, 0x1C);
    if (p[0x4B2] == 0) {
        M2C_FIELD(&sUnlockFunc, s8 *, 0x28)  = 9;
        M2C_FIELD(&sUnlockFunc, u8 **, 0x20) = p;
    } else {
        M2C_FIELD(&sUnlockFunc, s8 *, 0x28)  = 4;
        M2C_FIELD(&sUnlockFunc, u8 **, 0x20) = p + 0x220;
    }
    M2C_FIELD(&sUnlockFunc, u8 *, 0x24) = 3;
}
