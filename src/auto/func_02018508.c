#include "m2c.h"

s32 func_0205ab1c(u16);                             /* extern */
s32 func_0205ab58(u16);                             /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_020bbeb0(void *, s32);                 /* extern */
M2C_UNK func_020bbf78(void *, u16, s32, M2C_UNK);   /* extern */
void *func_020bbfe8();                              /* extern */
extern M2C_UNK data_020e5d08;
extern void *data_02101ae4;

void *func_02018508(void *arg0, s8 arg1) {
    s32 temp_r5;
    void *var_r0;

    M2C_FIELD(arg0, s16 *, 4) = 1;
    temp_r5 = (arg1 * 6) + (s32) &data_020e5d08;
    M2C_FIELD(arg0, s8 *, 6) = arg1;
    M2C_FIELD(arg0, s8 *, 7) = 0;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    var_r0 = func_0205e80c(0x3A0, 3, 4);
    if (var_r0 != NULL) {
        var_r0 = func_020bbfe8();
    }
    M2C_FIELD(arg0, void **, 0) = var_r0;
    func_020bbeb0(M2C_FIELD(arg0, void **, 0), func_0205ab1c(M2C_FIELD(temp_r5, u16 *, 2)));
    func_020bbf78(M2C_FIELD(arg0, void **, 0), M2C_FIELD(temp_r5, u16 *, 4), func_0205ab58(M2C_FIELD(temp_r5, u16 *, 4)), 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x39C) = 0;
    M2C_FIELD(data_02101ae4, M2C_UNK (**)(void **, void *), 8)(&data_02101ae4, arg0);
    return arg0;
}
