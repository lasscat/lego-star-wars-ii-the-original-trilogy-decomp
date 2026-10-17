#include "m2c.h"

M2C_UNK func_020536a8(void *, M2C_UNK);             /* extern */
void **func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */
void **func_020682c4(void **, void *, void *, void *, s32, s32, s32); /* extern */
void **func_0206e1e8(void **, void *, void *, void *, s32, s32, s32, s32, s32); /* extern */
void **func_02075d00(void **, void *);              /* extern */
M2C_UNK func_0208816c(void *);                      /* extern */
M2C_UNK func_0208837c(void *, M2C_UNK, u8);         /* extern */
M2C_UNK func_020887e0(void *);                      /* extern */
s32 func_02093fa8(s32);                             /* extern */

void func_02087a54(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    void **temp_r0;
    void **var_r0;
    void **var_r0_2;
    void **var_r0_3;

    temp_r0 = M2C_FIELD(arg0, void ***, 0xC4);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, M2C_UNK(**)(), 4)(temp_r0);
    }
    M2C_FIELD(arg0, void ***, 0xC4) = NULL;
    if (M2C_FIELD(arg0, u8 *, 0xC9) != 0) {
        M2C_FIELD(arg0, u8 *, 0xC9) = 0U;
        func_0208816c(arg0);
    }
    func_020887e0(arg0 + 0xE8);
    func_020536a8(arg0 + 0x30, 0);
    switch (arg1) {                                 /* irregular */
        case 0:
            var_r0 = func_0205e80c(0x2C, 3, 4);
            if (var_r0 != NULL) {
                var_r0 =
                    func_0206e1e8(var_r0, arg0, arg0 + 0x28, arg0 + 0x68, M2C_FIELD(arg3, s32 *, 0), M2C_FIELD(arg3, s32 *, 4),
                                  M2C_FIELD(arg3, s32 *, 8), M2C_FIELD(arg3, s32 *, 0xC), M2C_FIELD(arg3, s32 *, 0x10));
            }
            M2C_FIELD(arg0, void ***, 0xC4) = var_r0;
            return;
        case 1:
            if ((func_02093fa8(M2C_FIELD(arg3, s32 *, 0)) == 1) || (func_02093fa8(M2C_FIELD(arg3, s32 *, 0)) == 2)) {
                M2C_FIELD(arg0, u8 *, 0xC8) = 1U;
            }
            var_r0_2 = func_0205e80c(0x38, 3, 4);
            if (var_r0_2 != NULL) {
                var_r0_2 = func_020682c4(var_r0_2, arg0, arg0 + 0x28, arg0 + 0x68, M2C_FIELD(arg3, s32 *, 0),
                                         M2C_FIELD(arg3, s32 *, 4), (s32) M2C_FIELD(arg0, u8 *, 0xC8));
            }
            M2C_FIELD(arg0, void ***, 0xC4) = var_r0_2;
            M2C_FIELD(arg0, u8 *, 0xC9)     = 1U;
            return;
        case 3:
            func_0208837c(arg0 + 0xE8, 0, M2C_FIELD(arg0, u8 *, 0xC8));
            var_r0_3 = func_0205e80c(0x28, 3, 4);
            if (var_r0_3 != NULL) {
                var_r0_3 = func_02075d00(var_r0_3, arg0);
            }
            M2C_FIELD(arg0, void ***, 0xC4) = var_r0_3;
            func_020536a8(arg0 + 0x30, 1);
            return;
    }
}
