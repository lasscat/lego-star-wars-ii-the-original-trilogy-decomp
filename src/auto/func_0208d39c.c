#include "m2c.h"

M2C_UNK func_0205d4c8(void *, void *);              /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */

void func_0208d39c(void *arg0, s32 arg1) {
    void *var_r4;

    var_r4 = M2C_FIELD(arg0, void **, 4);
    if (var_r4 == NULL) {
        return;
    }
loop_2:
    if (M2C_FIELD(var_r4, s32 *, 0) == arg1) {
        func_0205e84c(arg1);
        func_0205d4c8(arg0, var_r4);
        return;
    }
    var_r4 = M2C_FIELD(var_r4, void **, 4);
    if (var_r4 == NULL) {
        return;
    }
    goto loop_2;
}
