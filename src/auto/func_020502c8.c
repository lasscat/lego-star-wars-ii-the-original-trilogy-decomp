#include "m2c.h"

void func_020502c8(void *arg0, void *arg1) {
    s32 temp_r1;
    s32 var_r3;
    void **var_r2;
    void *temp_r1_2;
    void *var_ip;

    if (M2C_FIELD(arg1, s32 *, 0x10) != 0) {
        M2C_FIELD(arg0, s8 *, 0) = 1;
        if ((arg0 + 4) != (arg1 + 0x18)) {
            M2C_FIELD(arg0, s32 *, 4)   = (s32) M2C_FIELD(arg1, s32 *, 0x18);
            M2C_FIELD(arg0, s32 *, 8)   = (s32) M2C_FIELD(arg1, s32 *, 0x1C);
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg1, s32 *, 0x20);
        }
        temp_r1 = M2C_FIELD(arg1, s32 *, 0x10);
        if (temp_r1 & 0x80000000) {
            var_r2 = M2C_FIELD(arg0, void ***, 0x14);
            var_r3 = temp_r1 & ~0x80000000;
            if (var_r3 != 0) {
                var_r3 += 4;
            }
            if (var_r2 != NULL) {
                var_ip    = *var_r2;
                temp_r1_2 = arg0 + 0x14;
                if (var_ip != temp_r1_2) {
                    do {
                        var_r2 = var_ip + 4;
                        var_ip = M2C_FIELD(var_ip, void **, 4);
                    } while (var_ip != temp_r1_2);
                }
                *var_r2 = M2C_FIELD(arg0, void **, 0x18);
            }
            if (var_r3 != 0) {
                M2C_FIELD(arg0, void ***, 0x14) = (void **) var_r3;
                M2C_FIELD(arg0, void **, 0x18)  = (void *) *(M2C_UNK *) var_r3;
                *(M2C_UNK *) var_r3             = (void *) (arg0 + 0x14);
            } else {
                M2C_FIELD(arg0, void ***, 0x14) = NULL;
                M2C_FIELD(arg0, void **, 0x18)  = NULL;
            }
            M2C_FIELD(arg0, s8 *, 1) = 1;
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x10) = temp_r1;
        M2C_FIELD(arg0, s8 *, 1)     = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0) = 0;
}
