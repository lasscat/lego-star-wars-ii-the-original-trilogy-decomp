#include "m2c.h"

M2C_UNK func_020b3770(void *, u8);                  /* extern */
M2C_UNK func_020b37c0(void *, u8);                  /* extern */
M2C_UNK func_020b3998(void *, u8);                  /* extern */
M2C_UNK func_020b90b0(M2C_UNK, u8, u8, u8);         /* extern */
s32 func_020e2c20(M2C_UNK, u8);                     /* extern */
extern M2C_UNK data_02104364;
extern s32 data_027e02a4;
extern s32 data_027e02a8;

void func_020b352c(void *arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r0_5;

    if (M2C_FIELD(arg0, u8 *, 4) != 0) {
        temp_r0 = M2C_FIELD(arg0, s32 *, 8);
        if (temp_r0 != 0) {
            M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r0 - 1);
        }
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 0xC);
        if (temp_r0_2 != 0) {
            temp_r0_3                   = temp_r0_2 - 1;
            M2C_FIELD(arg0, s32 *, 0xC) = temp_r0_3;
            if (temp_r0_3 == 0) {
                temp_r0_4 = M2C_FIELD(arg0, u8 *, 0x11);
                switch (temp_r0_4) {                /* irregular */
                    case 0:
                        func_020b37c0(arg0, M2C_FIELD(arg0, u8 *, 0x10));
                        if (M2C_FIELD(arg0, u8 *, 0x12) == M2C_FIELD(arg0, u8 *, 0x16)) {
                            func_020b3998(arg0, M2C_FIELD(arg0, u8 *, 0x10));
                        } else {
                            M2C_FIELD(arg0, u8 *, 0x11) = 1U;
                            if (M2C_FIELD(arg0, u8 *, 0x16) == 0x1D) {
                                M2C_FIELD(arg0, s32 *, 0xC) = 0;
                            } else {
                                func_020b90b0(0, M2C_FIELD(&data_02104364, u8 *, 0xA), 0U, M2C_FIELD(arg0, u8 *, 0x14));
                                M2C_FIELD(arg0, s32 *, 0xC) = func_020e2c20(0x5A, M2C_FIELD(arg0, u8 *, 0x14));
                            }
                        }
                        break;
                    case 1:
                        M2C_FIELD(arg0, u8 *, 0x11) = 2U;
                        func_020b3998(arg0, M2C_FIELD(arg0, u8 *, 0x10));
                        if (M2C_FIELD(arg0, u8 *, 0x16) != 0x1D) {
                            func_020b90b0(0, 0U, M2C_FIELD(&data_02104364, u8 *, 0xA), M2C_FIELD(arg0, u8 *, 0x14));
                        }
                        M2C_FIELD(arg0, s32 *, 0xC) = 0x32;
                        break;
                    case 2:
                        M2C_FIELD(arg0, u8 *, 0x11) = 0U;
                        M2C_FIELD(arg0, s32 *, 8)   = 0xA;
                        break;
                }
            }
        }
        if ((M2C_FIELD(arg0, s32 *, 0xC) == 0) && !(data_027e02a8 & (1 << data_027e02a4))) {
            if (M2C_FIELD(arg0, u8 *, 0x3F) != 0) {
                func_020b3770(arg0, 6U);
            } else if (M2C_FIELD(arg0, u8 *, 0x3E) != 0) {
                func_020b3770(arg0, 5U);
            } else if (M2C_FIELD(arg0, s32 *, 0x34) != 0) {
                func_020b3770(arg0, 3U);
            } else if (M2C_FIELD(arg0, u8 *, 0x38) != 0) {
                func_020b3770(arg0, M2C_FIELD(arg0, u8 *, 0x39));
            } else {
                func_020b3770(arg0, 0U);
            }
        }
    }
    temp_r0_5 = M2C_FIELD(arg0, u8 *, 0x38);
    if (temp_r0_5 != 0) {
        M2C_FIELD(arg0, u8 *, 0x38) = (u8) (temp_r0_5 - 1);
    }
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}
