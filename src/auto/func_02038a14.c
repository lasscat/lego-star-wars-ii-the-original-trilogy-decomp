#include "m2c.h"

M2C_UNK func_02038aa8(void *);                      /* extern */

void func_02038a14(void *arg0) {
    s16 temp_r2;
    void *temp_r0;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    if ((!(M2C_FIELD(temp_r1, u16 *, 0x5CE) & 1) || ((temp_r0 = M2C_FIELD(arg0, void **, 0x10), (temp_r0 != NULL)) && (M2C_FIELD(temp_r0, s32 *, 0x194) == 0)) || (temp_r2 = M2C_FIELD(temp_r1, s16 *, 0x6B6), (M2C_FIELD(arg0, u8 *, 0x18) != temp_r2)) || (M2C_FIELD(temp_r1, s32 *, 8) & 0x802) || (temp_r2 == 0)) && (M2C_FIELD(arg0, u8 *, 0xD) == 2)) {
        M2C_FIELD(arg0, u8 *, 0xD) = 4U;
        func_02038aa8(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x18) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x6B6);
}
