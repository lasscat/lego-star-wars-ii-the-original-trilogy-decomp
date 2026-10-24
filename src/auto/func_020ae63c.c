/* compiler: 2.0/sp1p5 -O2 */
#include "m2c.h"

s32 WM_GetAllowedChannel();                         /* extern */
s16 WM_GetDispersionScanPeriod();                   /* extern */
s32 WM_StartScan();             /* extern */
M2C_UNK func_020ad8b4();                     /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b380;
extern M2C_UNK data_0210b460;
extern M2C_UNK func_020ae704;

s32 func_020ae63c(void) {
    s32 temp_r0;

    temp_r0 = WM_GetAllowedChannel();
    if (temp_r0 == 0x8000) {
        func_020ad8b4(3);
        return 0;
    }
    if (temp_r0 == 0) {
        func_020ad8b4(0x16);
        return 0;
    }
    if (M2C_FIELD(&data_0210b320, u16 *, 6) == 0) {
    loop_6:
        M2C_FIELD(&data_0210b320, u16 *, 0x64) = (u16) (M2C_FIELD(&data_0210b320, u16 *, 0x64) + 1);
        if ((u32) M2C_FIELD(&data_0210b320, u16 *, 0x64) > 0x10U) {
            M2C_FIELD(&data_0210b320, u16 *, 0x64) = 1U;
        }
        if (!(temp_r0 & (1 << (M2C_FIELD(&data_0210b320, u16 *, 0x64) - 1)))) {
            goto loop_6;
        }
    } else {
        M2C_FIELD(&data_0210b320, u16 *, 0x64) = (u16) M2C_FIELD(&data_0210b320, u16 *, 6);
    }
    M2C_FIELD(&data_0210b320, s16 *, 0x66)      = WM_GetDispersionScanPeriod();
    M2C_FIELD(&data_0210b320, M2C_UNK **, 0x60) = &data_0210b460;
    if (WM_StartScan(&func_020ae704, &data_0210b380) == 2) {
        return 1;
    }
    func_020ad8b4();
    return 0;
}
