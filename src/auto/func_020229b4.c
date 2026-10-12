#include "m2c.h"

M2C_UNK func_0201214c();                            /* extern */

void func_020229b4(void *arg0, s32 arg1) {
    u16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u16 *, 0x212);
    if ((temp_r3 != 0x54) && (temp_r3 != 0x15D)) {
        if (M2C_FIELD(arg0, s32 *, 0x194) != 0x600) {
            M2C_FIELD(arg0, s8 *, 0x216) = 1;
            return;
        }
        func_0201214c(arg0, arg1);
        return;
    }
    func_0201214c(arg0, arg1);
}
