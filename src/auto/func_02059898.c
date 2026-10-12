#include "m2c.h"

M2C_UNK func_02060158(void **, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */
extern void *data_02102900;

void func_02059898(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;
    s32 var_r1;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    if (data_02102900 != NULL) {
        var_r1 = M2C_FIELD(data_02102900, s32 *, 4);
    } else {
        var_r1 = 0;
    }
    if (var_r1 != 4) {
        return;
    }
    func_02060158(&data_02102900, 0, 0x14, 1, temp_r0);
}
