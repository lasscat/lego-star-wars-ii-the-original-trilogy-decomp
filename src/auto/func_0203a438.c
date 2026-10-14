#include "m2c.h"

M2C_UNK func_0203a4c4(void *);                      /* extern */
s32 func_0205d060(M2C_UNK *, M2C_UNK, s32);         /* extern */
extern M2C_UNK data_021027f8;

void func_0203a438(void *arg0) {
    void *temp_r2;
    void *var_r0;

    if (func_0205d060(&data_021027f8, 1, M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
        var_r0 = M2C_FIELD(arg0, void **, 0x10);
        if (var_r0 != NULL) {
            var_r0 -= 4;
        }
        if ((M2C_FIELD(var_r0, s32 *, 0x194) == 0) ||
            (temp_r2 = M2C_FIELD(arg0, void **, 4), (M2C_FIELD(arg0, u16 *, 0x1C) != M2C_FIELD(temp_r2, s16 *, 0x6B6))) ||
            (M2C_FIELD(temp_r2, s32 *, 8) & 0x802)) {
            goto block_6;
        }
    } else {
    block_6:
        M2C_FIELD(arg0, s8 *, 0xD) = 4;
        func_0203a4c4(arg0);
    }
    M2C_FIELD(arg0, u16 *, 0x1C) = (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x6B6);
}
