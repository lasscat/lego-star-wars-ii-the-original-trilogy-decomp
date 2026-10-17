#include "m2c.h"

M2C_UNK func_020190b4(void *, void *, M2C_UNK);     /* extern */
M2C_UNK func_02019554(void *);                      /* extern */
s32 func_0202ca70(void *, M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK data_020f6bab;

void func_02019498(void *arg0, void **arg1) {
    u16 temp_r0;
    u8 temp_r0_2;
    void *temp_r4;

    if (M2C_FIELD(arg0, u8 *, 0x1C1) != 0) {
        return;
    }
    temp_r4 = *arg1;
    if (temp_r4 == NULL) {
        return;
    }
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 0xC);
    if ((temp_r0 != 1) && (temp_r0 != 2)) {
        return;
    }
    if ((temp_r0 == 2) && (M2C_FIELD(temp_r4, u8 *, 0x6BB) != 0xB)) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x1BC) == M2C_FIELD(temp_r4, u8 *, 0x5DA)) {
        return;
    }
    temp_r0_2 = *((u8 *) ((s8 *) &data_020f6bab + (M2C_FIELD(temp_r4, u8 *, 0x6C3) * 0x24)));
    if ((temp_r0_2 != 0) && (temp_r0_2 != 2)) {
        return;
    }
    if (temp_r0_2 == 0) {
        if (func_0202ca70(temp_r4 + 0x5E0, 7, arg0, 2) != 0) {
            return;
        }
        func_020190b4(arg0, temp_r4, 0x28);
        return;
    }
    func_02019554(arg0);
}
