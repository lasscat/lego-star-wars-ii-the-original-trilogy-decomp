#include "m2c.h"

s32 PMi_SetLED(M2C_UNK arg0);
s32 PMi_SetLEDAsync(s32 arg0, void *arg1, void *arg2);
extern M2C_UNK data_0211748c;

s32 PMi_SetLCDPower(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != 0) {
        if (arg0 == 1) {
            if (arg2 == 0) {
                u32 diff = *(s32 *) 0x027FFC3C - M2C_FIELD(&data_0211748c, s32 *, 0x10);
                if (diff <= 7) {
                    return 0;
                }
            }
            if (arg1 != 0) {
                if (arg3 != 0) {
                    PMi_SetLED(arg1);
                } else {
                    PMi_SetLEDAsync(arg1, 0, 0);
                }
            }
            *(u16 *) 0x04000304 |= 1;
        }
    } else {
        *(u16 *) 0x04000304 &= ~1;
        M2C_FIELD(&data_0211748c, s32 *, 0x10) = *(s32 *) 0x027FFC3C;
        if (arg1 != 0) {
            if (arg3 != 0) {
                PMi_SetLED(arg1);
            } else {
                PMi_SetLEDAsync(arg1, 0, 0);
            }
        }
    }
    return 1;
}
