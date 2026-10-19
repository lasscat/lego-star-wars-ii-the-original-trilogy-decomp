#include "m2c.h"

void func_020c39d4(void **arg0, void *arg1) {
    void *var_ip;
    void *var_r2;
    void *var_r3;

    var_ip = *arg0;
    if (var_ip == NULL) {
        *arg0 = arg1;
        return;
    }
    var_r2 = M2C_FIELD(var_ip, void **, 0x10);
    if (var_r2 == NULL) {
        if ((u32) M2C_FIELD(var_ip, u8 *, 0x18) > (u32) M2C_FIELD(arg1, u8 *, 0x18)) {
            var_r3 = arg1;
            if (M2C_FIELD(arg1, s32 *, 0x10) != 0) {
                do {
                    var_r3 = M2C_FIELD(var_r3, void **, 0x10);
                } while (M2C_FIELD(var_r3, s32 *, 0x10) != 0);
            }
            M2C_FIELD(var_r3, void **, 0x10) = var_ip;
            *arg0                            = arg1;
            return;
        }
        M2C_FIELD(var_ip, void **, 0x10) = arg1;
        return;
    }
    while (var_r2 != NULL) {
        if ((u32) M2C_FIELD(var_r2, u8 *, 0x18) >= (u32) M2C_FIELD(arg1, u8 *, 0x18)) {
            var_r3 = arg1;
            if (M2C_FIELD(arg1, s32 *, 0x10) != 0) {
                do {
                    var_r3 = M2C_FIELD(var_r3, void **, 0x10);
                } while (M2C_FIELD(var_r3, s32 *, 0x10) != 0);
            }
            M2C_FIELD(var_ip, void **, 0x10) = arg1;
            M2C_FIELD(var_r3, void **, 0x10) = var_r2;
            return;
        }
        var_ip = var_r2;
        var_r2 = M2C_FIELD(var_r2, void **, 0x10);
    }
    M2C_FIELD(var_ip, void **, 0x10) = arg1;
}
