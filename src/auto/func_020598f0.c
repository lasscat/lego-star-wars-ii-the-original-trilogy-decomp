#include "m2c.h"

M2C_UNK func_02060158(void **, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern void *data_02102900;

void func_020598f0(void) {
    s32 var_r0;

    if (data_02102900 != NULL) {
        var_r0 = M2C_FIELD(data_02102900, s32 *, 4);
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 4) {
        return;
    }
    func_02060158(&data_02102900, 0, 0x14, 1, 0);
}
