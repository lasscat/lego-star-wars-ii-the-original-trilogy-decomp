#include "m2c.h"

s32 func_0205ab44(s32);                             /* extern */
s32 func_0205ab58(M2C_UNK);                         /* extern */
void *func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_020bbeb0(void *, s32);                 /* extern */
M2C_UNK func_020bbf78(void *, M2C_UNK, s32, M2C_UNK); /* extern */
void *func_020bbfe8();                              /* extern */
extern void *data_02102900;

void func_0201d14c(void *arg0) {
    s32 var_r0_2;
    void *var_r0;

    if (M2C_FIELD(arg0, void **, 0x1C8) != NULL) {
        return;
    }
    var_r0 = func_0205e80c(0x3A0, 3, 4);
    if (var_r0 != NULL) {
        var_r0 = func_020bbfe8();
    }
    M2C_FIELD(arg0, void **, 0x1C8) = var_r0;
    func_020bbeb0(M2C_FIELD(arg0, void **, 0x1C8), func_0205ab44(0x1137));
    func_020bbf78(M2C_FIELD(arg0, void **, 0x1C8), 0x224, func_0205ab58(0x224), 0);
    if (data_02102900 != NULL) {
        var_r0_2 = M2C_FIELD(data_02102900, s32 *, 4);
    } else {
        var_r0_2 = 0;
    }
    if (var_r0_2 != 9) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C8), s8 *, 0x39C) = 0;
    }
}
