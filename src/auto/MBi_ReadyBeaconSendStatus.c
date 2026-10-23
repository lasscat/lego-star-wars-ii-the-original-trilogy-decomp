#include "m2c.h"

extern M2C_UNK sUnlockFunc;
extern M2C_UNK bsendBuff;

s32 MBi_GetGgid(void);   /* extern */
u16 MBi_GetTgid(void);   /* extern */
void WM_SetGameInfo(s32, void *, u32, s32, u16, u8);   /* extern */
void MBi_ClearSendStatus(void);   /* extern */

s32 MBi_ReadyBeaconSendStatus(void) {
    void *p;
    void *v;

    if (M2C_FIELD(&sUnlockFunc, u32 *, 0x18) == 0) {
        WM_SetGameInfo(0, &bsendBuff, 0x70, MBi_GetGgid(), MBi_GetTgid(), 8);
        return 0;
    }
    p = M2C_FIELD(&sUnlockFunc, void **, 0x1c);
    if (p != 0 && M2C_FIELD(p, void **, 0x4bc) != 0) {
        v = M2C_FIELD(p, void **, 0x4bc);
    } else {
        v = M2C_FIELD(&sUnlockFunc, void **, 0x18);
    }
    M2C_FIELD(&sUnlockFunc, void **, 0x1c) = v;
    MBi_ClearSendStatus();
    M2C_FIELD(&sUnlockFunc, u8 *, 0x26) = M2C_FIELD(M2C_FIELD(&sUnlockFunc, void **, 0x1c), u8 *, 0x4b4);
    M2C_FIELD(&sUnlockFunc, s8 *, 0x24) = 2;
    return 1;
}
