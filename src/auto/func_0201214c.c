/* Reconstructed from USA ARM9 at 0x0201214c (368 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0201511c();                            /* extern */

void func_0201214c(void *arg0, void **arg1) {
    u32 temp_r2;
    void **var_r1;
    void **var_r3;
    void **var_r3_2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *var_ip;
    void *var_ip_2;

    var_r1  = arg1;
    temp_r2 = M2C_FIELD(arg0, u32 *, 0x194);
    switch (temp_r2) {
        case 0x8600:
        case 0x600:
        case 0x400:
        case 0x200:
            M2C_FIELD(arg0, u16 *, 0x210) = (u16) (M2C_FIELD(arg0, u16 *, 0x210) | 1);
            M2C_FIELD(arg0, s8 *, 0x214)  = 5;
            M2C_FIELD(arg0, s8 *, 0x1AD)  = 1;
            var_r3                        = M2C_FIELD(arg0, void ***, 0x1D0);
            if (var_r1 != NULL) {
                var_r1 += 1;
            }
            if (var_r3 != NULL) {
                var_ip    = *var_r3;
                temp_r2_2 = arg0 + 0x1D0;
                if (var_ip != temp_r2_2) {
                    do {
                        var_r3 = var_ip + 4;
                        var_ip = M2C_FIELD(var_ip, void **, 4);
                    } while (var_ip != temp_r2_2);
                }
                *var_r3 = M2C_FIELD(arg0, void **, 0x1D4);
            }
            if (var_r1 != NULL) {
                M2C_FIELD(arg0, void ***, 0x1D0) = var_r1;
                M2C_FIELD(arg0, void **, 0x1D4)  = (void *) *var_r1;
                *var_r1                          = arg0 + 0x1D0;
                return;
            }
            M2C_FIELD(arg0, void ***, 0x1D0) = NULL;
            M2C_FIELD(arg0, void **, 0x1D4)  = NULL;
            return;
        case 0x800:
            M2C_FIELD(arg0, u16 *, 0x210) = (u16) (M2C_FIELD(arg0, u16 *, 0x210) | 1);
            M2C_FIELD(arg0, s8 *, 0x214)  = 0x12;
            M2C_FIELD(arg0, s8 *, 0x1AD)  = 1;
            var_r3_2                      = M2C_FIELD(arg0, void ***, 0x1D0);
            if (var_r1 != NULL) {
                var_r1 += 1;
            }
            if (var_r3_2 != NULL) {
                var_ip_2  = *var_r3_2;
                temp_r2_3 = arg0 + 0x1D0;
                if (var_ip_2 != temp_r2_3) {
                    do {
                        var_r3_2 = var_ip_2 + 4;
                        var_ip_2 = M2C_FIELD(var_ip_2, void **, 4);
                    } while (var_ip_2 != temp_r2_3);
                }
                *var_r3_2 = M2C_FIELD(arg0, void **, 0x1D4);
            }
            if (var_r1 != NULL) {
                M2C_FIELD(arg0, void ***, 0x1D0) = var_r1;
                M2C_FIELD(arg0, void **, 0x1D4)  = (void *) *var_r1;
                *var_r1                          = arg0 + 0x1D0;
                return;
            }
            M2C_FIELD(arg0, void ***, 0x1D0) = NULL;
            M2C_FIELD(arg0, void **, 0x1D4)  = NULL;
            return;
        case 0x20:
            func_0201511c();
            return;
    }
}
