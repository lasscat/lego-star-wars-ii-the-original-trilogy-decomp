#include "m2c.h"

M2C_UNK func_020a99bc(s32, M2C_UNK);                /* extern */
s32 func_020aaeb4();                                /* extern */
extern M2C_UNK data_021027f8;

void func_0204b450(void *arg0) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r3, void **, 0x6AC) == NULL) {
        M2C_FIELD(arg0, s8 *, 0xD) = 4;
        M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
        if (M2C_FIELD(temp_r3, u8 *, 0x5DA) != M2C_FIELD(&data_021027f8, u8 *, 0x2A)) {
            return;
        }
        func_020a99bc(func_020aaeb4(), 9);
        return;
    }
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x6AC), s8 *, 0x1AD) = 1;
}
