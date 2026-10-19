#include "m2c.h"

M2C_UNK func_0209d118(s32, u8);                     /* extern */
extern M2C_UNK data_02106d90;

void func_0203a4c4(void *arg0) {
    s32 temp_r0;
    u32 temp_r1;
    s8 *var_r0;
    s8 *var_r1;
    s8 *var_r1_2;

    M2C_FIELD(arg0, s8 *, 0x24) = 1;
    var_r0                      = M2C_FIELD(arg0, s8 **, 0x10);
    var_r1                      = var_r0;
    if (var_r0 != NULL) {
        var_r1 = var_r0 - 4;
    }
    if (var_r1 == NULL) {
        return;
    }
    var_r1_2 = var_r0;
    if (var_r0 != NULL) {
        var_r1_2 = var_r0 - 4;
    }
    if (M2C_FIELD(var_r1_2, s32 *, 0x194) != 0) {
        if (var_r0 != NULL) {
            var_r0 -= 4;
        }
        M2C_FIELD(M2C_FIELD(var_r0, void **, 0), M2C_UNK(**)(void *, void *), 0x3C)(var_r0, M2C_FIELD(arg0, void **, 4));
        return;
    }
    temp_r0 = M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 0x10);
    if (temp_r0 == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x5DA);
    if ((u32) temp_r1 >= 4U) {
        return;
    }
    func_0209d118(temp_r0, (u8) temp_r1);
}
