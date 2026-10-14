#include "m2c.h"

extern M2C_UNK data_0211179c;

void func_020c0f68(void) {
    s32 var_r1;
    void *var_r0;

    var_r1 = 0;
    var_r0 = M2C_FIELD(&data_0211179c, void **, 0x7C0);
    if (var_r0 == NULL) {
        return;
    }
    do {
        M2C_FIELD(var_r0, s32 *, 4) = var_r1;
        var_r0                      = M2C_FIELD(var_r0, void **, 0x6C);
        var_r1 += 1;
    } while (var_r0 != NULL);
}
