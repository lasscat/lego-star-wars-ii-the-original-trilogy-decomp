#include "m2c.h"

M2C_UNK func_02004404(void *, M2C_UNK);             /* extern */
M2C_UNK func_020045c8(void *);                      /* extern */
M2C_UNK func_02004b00(void *);                      /* extern */
s32 func_0207b33c();                                /* extern */

void func_0207b3bc(void *arg0, M2C_UNK arg1) {
    s32 var_r4;
    u8 temp_r0;

    if (func_0207b33c() == 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x6C4);
    var_r4  = 0;
    if (!(temp_r0 & 2)) {
        var_r4 = 1;
    }
    if (temp_r0 & 4) {
        var_r4 = 1;
    }
    func_02004404(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x6C4) & 4) {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        func_02004b00(arg0);
    }
    func_020045c8(arg0);
}
