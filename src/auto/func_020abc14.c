#include "m2c.h"

s32 func_020abc14(void *arg0, s32 arg1) {
    s32 var_r3;
    void *temp_r2;
    void *var_ip;

    var_ip = M2C_FIELD(arg0, void **, 4);
    var_r3 = 0;
    if (var_ip != NULL) {
        do {
            temp_r2 = M2C_FIELD(var_ip, void **, 0);
            if (arg1 == M2C_FIELD(temp_r2, u16 *, 0x10)) {
                var_r3 += 1;
                M2C_FIELD(temp_r2, u16 *, 0x14) = (u16) (M2C_FIELD(temp_r2, u16 *, 0x14) | 1);
            }
            var_ip = M2C_FIELD(var_ip, void **, 4);
        } while (var_ip != NULL);
    }
    return var_r3 + 1;
}
