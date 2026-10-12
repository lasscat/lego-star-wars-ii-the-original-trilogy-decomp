#include "m2c.h"

M2C_UNK func_02003728(void *);                      /* extern */
M2C_UNK func_0200ee24();                            /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fcf28;

void *func_0200da24(void *arg0) {
    void **var_r1;
    void **var_r1_2;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *var_r2;
    void *var_r2_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcf28;
    func_0200ee24();
    temp_r1 = M2C_FIELD(arg0, void **, 0x810);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 2);
    }
    temp_r1_2 = M2C_FIELD(arg0, void **, 0x814);
    if (temp_r1_2 != NULL) {
        M2C_FIELD(temp_r1_2, s32 *, 8) = (s32) (M2C_FIELD(temp_r1_2, s32 *, 8) | 2);
    }
    temp_r1_3 = M2C_FIELD(arg0, void **, 0x818);
    if (temp_r1_3 != NULL) {
        M2C_FIELD(temp_r1_3, s32 *, 8) = (s32) (M2C_FIELD(temp_r1_3, s32 *, 8) | 2);
    }
    var_r1 = M2C_FIELD(arg0, void ***, 0x828);
    if (var_r1 != NULL) {
        var_r2 = *var_r1;
        temp_r0 = arg0 + 0x828;
        if (var_r2 != temp_r0) {
            do {
                var_r1 = var_r2 + 4;
                var_r2 = M2C_FIELD(var_r2, void **, 4);
            } while (var_r2 != temp_r0);
        }
        *var_r1 = M2C_FIELD(arg0, void **, 0x82C);
    }
    var_r1_2 = M2C_FIELD(arg0, void ***, 0x820);
    if (var_r1_2 != NULL) {
        var_r2_2 = *var_r1_2;
        temp_r0_2 = arg0 + 0x820;
        if (var_r2_2 != temp_r0_2) {
            do {
                var_r1_2 = var_r2_2 + 4;
                var_r2_2 = M2C_FIELD(var_r2_2, void **, 4);
            } while (var_r2_2 != temp_r0_2);
        }
        *var_r1_2 = M2C_FIELD(arg0, void **, 0x824);
    }
    func_02003728(arg0);
    func_0205e84c(arg0);
    return arg0;
}
