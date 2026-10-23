#include "m2c.h"

M2C_UNK func_020e4600(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_02066ec4;

void func_02066e20(void *arg0, void *arg1) {
    void *var_r0;
    u32 i;

    if (M2C_FIELD(arg0, u16 *, 0xC16) == 0) {
        return;
    }
    var_r0 = M2C_FIELD(arg0, void **, 0xC);
    if (var_r0 != NULL) {
        var_r0 = func_020e4600(var_r0, M2C_FIELD(arg0, u16 *, 0xC16), 4, 0, &func_02066ec4, 0);
    }
    M2C_FIELD(arg0, void **, 0)   = var_r0;
    M2C_FIELD(arg0, void **, 0xC) = M2C_FIELD(arg0, void **, 0xC) + (M2C_FIELD(arg0, u16 *, 0xC16) * 4 + 8);
    for (i = 0; i < M2C_FIELD(arg0, u16 *, 0xC16); i++) {
        ((void **) M2C_FIELD(arg0, void **, 0))[i] = arg1;
        arg1                                       = (u8 *) arg1 + 0x10;
    }
}
