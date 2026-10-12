#include "m2c.h"

M2C_UNK func_0201aa38(void *);                      /* extern */
M2C_UNK func_0201af8c(void *);                      /* extern */
M2C_UNK func_0201b48c(void *);                      /* extern */
M2C_UNK func_02060e38();                            /* extern */
M2C_UNK func_02060e50();                            /* extern */
extern s32 data_027e02a8;

void func_0201ae44(void *arg0) {
    s32 temp_r4;
    s32 var_r1;

    temp_r4 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r4 & 0x10) {
        if (temp_r4 & 0x400) {
            if (!(temp_r4 & 0x80000)) {
                func_02060e38();
            }
        } else if (temp_r4 & 0x80000) {
            func_02060e50();
        }
    }
    if (data_027e02a8 & 0x200) {
        var_r1 = 0;
    } else if (M2C_FIELD(arg0, s32 *, 8) & 0x80000000) {
        var_r1 = 0;
    } else {
        var_r1 = 1;
    }
    if (!(data_027e02a8 & (0x10 << var_r1))) {
        if (temp_r4 & 0x400) {
            if (!(temp_r4 & 0x40000)) {
                if ((temp_r4 & 8) && (M2C_FIELD(arg0, u8 *, 0x18) != 0)) {
                    func_0201af8c(arg0);
                }
                if (M2C_FIELD(arg0, u16 *, 0x3E) != 0) {
                    func_0201aa38(arg0);
                }
                M2C_FIELD(arg0, s32 *, 0x64) = (s32) (M2C_FIELD(arg0, s32 *, 0x64) + M2C_FIELD(arg0, s32 *, 0x6C));
                M2C_FIELD(arg0, s32 *, 0x68) = (s32) (M2C_FIELD(arg0, s32 *, 0x68) + M2C_FIELD(arg0, s32 *, 0x70));
                M2C_FIELD(arg0, s32 *, 0x54) = (s32) (M2C_FIELD(arg0, s32 *, 0x4C) + M2C_FIELD(arg0, s32 *, 0x64));
                M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x50) + M2C_FIELD(arg0, s32 *, 0x68));
                M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x54);
                M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0x58);
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
    }
    if (temp_r4 & 0x400000) {
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x42) == 0xFFFF) {
        return;
    }
    func_0201b48c(arg0);
}
