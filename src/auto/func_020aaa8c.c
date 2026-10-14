#include "engine.h"
#include "m2c.h"

void func_020aa7c0(M2C_UNK, M2C_UNK);

void func_020aaa8c(s32 arg0) {
    void *temp_r1;
    void *var_r4;

    var_r4 = M2C_FIELD(arg0, void **, 0x398);
    if (var_r4 == NULL) {
        return;
    }
    do {
        temp_r1 = M2C_FIELD(var_r4, void **, 0);
        if ((temp_r1 != NULL) && ((u32) (M2C_FIELD(temp_r1, s32 *, 0x24) - 2) <= 1U)) {
            func_020aa7c0(arg0, (s32) temp_r1);
        }
        var_r4 = M2C_FIELD(var_r4, void **, 4);
    } while (var_r4 != NULL);
}
