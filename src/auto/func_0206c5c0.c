#include "m2c.h"

s32 func_02053b14(void *);                          /* extern */
M2C_UNK func_0206adbc(s32);                         /* extern */
M2C_UNK func_020cf27c(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK data_02106d90;

u32 func_0206c5c0(void *arg0) {
    u32 temp_r0;
    void *temp_r1;

    M2C_FIELD(arg0, s32 *, 0x60) = 6;
    M2C_FIELD(arg0, u16 *, 0x880) = (u16) ((M2C_FIELD(arg0, u16 *, 0x880) & ~1) | 1);
    M2C_FIELD(arg0, s32 *, 0x5C) = 2;
    if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
        func_020cf27c(M2C_FIELD(arg0, s32 *, 0x40), func_02053b14(arg0 + 0x54), 0x800);
    }
    temp_r1 = arg0 + (M2C_FIELD(arg0, s32 *, 0x54) << 5);
    if ((M2C_FIELD(temp_r1, u16 *, 0x18) == 0) && (M2C_FIELD(temp_r1, u16 *, 0x1A) == 0) && (M2C_FIELD(temp_r1, u16 *, 0x1C) == 0)) {

    } else {
        M2C_FIELD(arg0, s32 *, 0x60) = 7;
    }
    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 0x880) << 0x1A) >> 0x1F;
    if (temp_r0 == 0) {
        return temp_r0;
    }
    func_0206adbc(M2C_FIELD(&data_02106d90, s32 *, 0xAD4));
    M2C_FIELD(arg0, u16 *, 0x880) = (u16) (M2C_FIELD(arg0, u16 *, 0x880) & ~0x20);
    return (u32) (arg0 + 0x800);
}
