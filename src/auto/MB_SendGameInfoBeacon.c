#include "m2c.h"

extern M2C_UNK sUnlockFunc;

M2C_UNK MBi_ReadyBeaconSendStatus(void);
void MBi_InitSendFixedBeacon(void);
void MBi_SendFixedBeacon(s32, s32, s32);
void MBi_InitSendVolatBeacon(void);
void MBi_SendVolatBeacon(s32, s32, s32);

void MB_SendGameInfoBeacon(s32 a0, s32 a1, s32 a2) {
    for (;;) {
        switch (M2C_FIELD(&sUnlockFunc, u8 *, 0x24)) {
            case 0:
            case 1:
                if (MBi_ReadyBeaconSendStatus() != 0) {
                    break;
                }
                return;
            case 2:
                MBi_InitSendFixedBeacon();
                break;
            case 3:
                MBi_SendFixedBeacon(a0, a1, a2);
                return;
            case 4:
                MBi_InitSendVolatBeacon();
                break;
            case 5:
                MBi_SendVolatBeacon(a0, a1, a2);
                return;
            case 6:
                break;
            default:
                break;
        }
    }
}
