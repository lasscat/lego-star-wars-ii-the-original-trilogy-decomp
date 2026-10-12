#include "m2c.h"

M2C_UNK func_02044ed0();                            /* extern */
extern s32 data_02104d90;

void func_02044e80(void *arg0) {
    void *temp_r1;

    if (!(M2C_FIELD(arg0, u8 *, 0xC) & 2)) {
        return;
    }
    if (!(data_02104d90 & 1) && (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x5D6) == 0)) {
        func_02044ed0();
        return;
    }
    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 0x200);
}
