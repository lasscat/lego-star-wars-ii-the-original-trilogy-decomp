#include "m2c.h"

M2C_UNK func_0204c88c(void *, s32);                 /* extern */
s32 func_0205ab1c();                                /* extern */
void *func_0205e80c(s32, M2C_UNK, M2C_UNK);         /* extern */
void *func_02066d30(void *, s32, u8);               /* extern */
M2C_UNK func_0208f14c(void *, s32, s32, s32, u32);  /* extern */
s32 func_02093f30(u8);                              /* extern */
s32 func_02093f44(u8);                              /* extern */
s32 func_02093f58(u8);                              /* extern */
u32 func_02093fbc(u8);                              /* extern */
s32 func_02093fe4(u8, u32);                         /* extern */
s32 func_02093ffc(u8);                              /* extern */
s32 func_02094024(u8);                              /* extern */

void func_0208fd4c(void *arg0) {
    u32 var_r5;
    s32 var_r6;
    void *var_r7;
    s32 temp_r8;
    u32 var_r9;
    u32 temp_r0;
    s32 temp_r0_3;
    s32 temp_r0_5;
    void *temp_r0_2;
    void *temp_r0_4;
    void *var_r5_2;

    temp_r8                       = func_02093ffc(M2C_FIELD(arg0, u8 *, 0x479));
    var_r6                        = func_02094024(M2C_FIELD(arg0, u8 *, 0x479));
    M2C_FIELD(arg0, u32 *, 0x3C8) = func_02093fbc(M2C_FIELD(arg0, u8 *, 0x479));
    var_r9                        = M2C_FIELD(arg0, u32 *, 0x3C8);
    var_r5                        = 0;
    if (var_r9 != 0) {
        var_r7 = arg0;
        do {
            func_0208f14c(var_r7, func_02093fe4(M2C_FIELD(arg0, u8 *, 0x479), var_r5), temp_r8, var_r6, var_r9);
            var_r9 = M2C_FIELD(arg0, u32 *, 0x3C8);
            var_r5 += 1;
            var_r6 += 8;
            var_r7 += 0x24;
        } while (var_r5 < var_r9);
    }
    if (func_02093f44(M2C_FIELD(arg0, u8 *, 0x479)) != 0xFFFF) {
        temp_r0_2 = func_0205e80c(0x14, 0, 4);
        if (temp_r0_2 != NULL) {
            temp_r0_3                         = func_02093f44(M2C_FIELD(arg0, u8 *, 0x479));
            M2C_FIELD(temp_r0_2, s32 *, 8)    = 0;
            M2C_FIELD(temp_r0_2, s32 *, 0xC)  = 0;
            M2C_FIELD(temp_r0_2, s32 *, 0x10) = 0;
            func_0204c88c(temp_r0_2, temp_r0_3);
        }
        M2C_FIELD(arg0, void **, 0x388) = temp_r0_2;
    }
    if (func_02093f30(M2C_FIELD(arg0, u8 *, 0x479)) != 0xFFFF) {
        temp_r0_4 = func_0205e80c(0x14, 0, 4);
        if (temp_r0_4 != NULL) {
            temp_r0_5                         = func_02093f30(M2C_FIELD(arg0, u8 *, 0x479));
            M2C_FIELD(temp_r0_4, s32 *, 8)    = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0xC)  = 0;
            M2C_FIELD(temp_r0_4, s32 *, 0x10) = 0;
            func_0204c88c(temp_r0_4, temp_r0_5);
        }
        M2C_FIELD(arg0, void **, 0x384) = temp_r0_4;
    }
    if (func_02093f58(M2C_FIELD(arg0, u8 *, 0x479)) == 0xFFFF) {
        return;
    }
    var_r5_2 = func_0205e80c(0xC1C, 0, 4);
    if (var_r5_2 != NULL) {
        func_02093f58(M2C_FIELD(arg0, u8 *, 0x479));
        var_r5_2 = func_02066d30(var_r5_2, func_0205ab1c(), M2C_FIELD(arg0, u8 *, 0x47B));
    }
    M2C_FIELD(arg0, void **, 0x38C) = var_r5_2;
}
