#include "m2c.h"

s32 func_0205d060(M2C_UNK *, M2C_UNK, s32);         /* extern */
s32 func_0205d140(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_021027f8;

void func_0203a6e8(void *arg0) {
    void *temp_r0;
    void *temp_r0_2;

    if ((func_0205d060(&data_021027f8, 0xF0, M2C_FIELD(arg0, s32 *, 0x14)) != 0) &&
        (M2C_FIELD(arg0, s32 *, 0x18) == func_0205d140(&data_021027f8, M2C_FIELD(arg0, s32 *, 0x14)))) {
        temp_r0 = M2C_FIELD(arg0, void **, 0x10);
        if (temp_r0 == NULL) {
            return;
        }
        if (M2C_FIELD(temp_r0, s32 *, 0x194) != 0) {
            return;
        }
        goto block_6;
    }
block_6:
    M2C_FIELD(arg0, s8 *, 0xD) = 4;
    temp_r0_2                  = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_r0_2, s32 *, 0x194) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(temp_r0_2, void **, 0), M2C_UNK(**)(void *, s32), 0x3C)(temp_r0_2, M2C_FIELD(arg0, s32 *, 4));
}
