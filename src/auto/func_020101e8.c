#include "m2c.h"

M2C_UNK func_020100ec(void *, void *, s32);         /* extern */
M2C_UNK func_0201c778(M2C_UNK *);                   /* extern */
M2C_UNK func_0201c7e8(M2C_UNK *, s32);              /* extern */
s32 func_0201c9e8(M2C_UNK *);                       /* extern */
u16 func_0201ca1c(u16);                             /* extern */
M2C_UNK func_0205c368(s32);                         /* extern */
M2C_UNK func_0205c8b0(s32, void *);                 /* extern */
M2C_UNK func_0205ccd4(void *);                      /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_02064f7c(s32);                         /* extern */
M2C_UNK func_02064f90(s32);                         /* extern */
M2C_UNK func_0209f590(void *);                      /* extern */
M2C_UNK func_020ab40c(void *, u16);                 /* extern */
M2C_UNK func_020ab574(void *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK data_020eb7b8;

void func_020101e8(void *arg0, s32 arg1, s32 arg2) {
    u8 sp0[12];
    s32 temp_r0_2;
    s32 temp_r9;
    s32 var_r4;
    u16 temp_r0;
    u16 temp_r5;

    if (arg1 == M2C_FIELD(arg0, u16 *, 0x180)) {
        return;
    }
    temp_r5 = M2C_FIELD(arg0, u16 *, 0xEA);
    func_0201c778(sp0);
    var_r4 = 0;
    if (arg2 != 0) {
        func_0201c7e8(sp0, M2C_FIELD(arg0, s32 *, 0xE0) + 0x14);
        var_r4 = func_0201c9e8(sp0);
        if (var_r4 != 0) {
            func_02064f90(M2C_FIELD(arg0, s32 *, 0xE0));
        }
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 0x1A8);
    if (temp_r0 & 1) {
        M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (temp_r0 & ~1);
        func_0209f590(arg0 + 0xD4);
        func_0205ccd4(arg0 + 0x2C);
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x190);
        if (temp_r0_2 != 0) {
            func_0205c8b0(temp_r0_2, arg0);
            temp_r9 = M2C_FIELD(arg0, s32 *, 0x190);
            if (temp_r9 != 0) {
                func_0205c368(temp_r9);
                func_0205e84c(temp_r9);
            }
            M2C_FIELD(arg0, s32 *, 0x190) = 0;
        }
    }
    func_020100ec(arg0, (M2C_UNK *) ((s8 *) &data_020eb7b8 + (arg1 * 8)), arg1);
    if (arg2 == 0) {
        return;
    }
    if (temp_r5 != 0xFFFF) {
        func_020ab40c(arg0 + 0xD8, temp_r5);
    } else {
        func_020ab40c(arg0 + 0xD8, func_0201ca1c(M2C_FIELD(arg0, u16 *, 0x180)));
    }
    if (var_r4 == 0) {
        return;
    }
    func_020ab574(arg0 + 0xD8, sp0, 1);
    func_02064f7c(M2C_FIELD(arg0, s32 *, 0xE0));
}
