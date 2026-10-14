/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_021111ec;

void func_020bbac0(void) {
    s32 var_r2;
    void *var_r1;

    var_r2 = 0;
    var_r1 = M2C_FIELD(&data_021111ec, void **, 0x5AC);
    if (var_r1 == NULL) {
        return;
    }
    do {
        M2C_FIELD(var_r1, s32 *, 0x4C) = var_r2;
        M2C_FIELD(var_r1, s32 *, 0x48) = 0;
        var_r1                         = M2C_FIELD(var_r1, void **, 0x90);
        var_r2 += 1;
    } while (var_r1 != NULL);
}
