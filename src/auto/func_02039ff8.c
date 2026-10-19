#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe0d8;

void func_02039ff8(void *arg0, void *arg1, s8 *arg2) {
    s8 *var_ip;
    s8 *var_r2;
    void *temp_r3;
    s8 *var_lr;

    var_r2                         = arg2;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(arg0, void **, 4)    = arg1;
    M2C_FIELD(arg0, s8 *, 0xC)     = 0;
    M2C_FIELD(arg0, s8 *, 0xD)     = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe0d8;
    M2C_FIELD(arg0, s8 **, 0x10)   = NULL;
    M2C_FIELD(arg0, void **, 0x14) = NULL;
    M2C_FIELD(arg0, s32 *, 0x20)   = 0;
    M2C_FIELD(arg0, s8 *, 0x24)    = 0;
    var_ip                         = M2C_FIELD(arg0, s8 **, 0x10);
    if (var_r2 != NULL) {
        var_r2 += 4;
    }
    if (var_ip != NULL) {
        var_lr  = M2C_FIELD(var_ip, s8 **, 0);
        temp_r3 = arg0 + 0x10;
        if (var_lr != temp_r3) {
            do {
                var_ip = var_lr + 4;
                var_lr = M2C_FIELD(var_lr, s8 **, 4);
            } while (var_lr != temp_r3);
        }
        M2C_FIELD(var_ip, void **, 0) = M2C_FIELD(arg0, void **, 0x14);
    }
    if (var_r2 != NULL) {
        M2C_FIELD(arg0, s8 **, 0x10)   = var_r2;
        M2C_FIELD(arg0, void **, 0x14) = M2C_FIELD(var_r2, void **, 0);
        M2C_FIELD(var_r2, void **, 0)  = arg0 + 0x10;
    } else {
        M2C_FIELD(arg0, s8 **, 0x10)   = NULL;
        M2C_FIELD(arg0, void **, 0x14) = NULL;
    }
    M2C_FIELD(arg0, s16 *, 0x1C) = (s16) M2C_FIELD(arg1, s16 *, 0x6B6);
}
