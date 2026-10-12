#include "m2c.h"

M2C_UNK func_0208e874(void *, M2C_UNK);             /* extern */

void func_0208e82c(void *arg0, s32 arg1, s32 arg2) {
    void *temp_r1;

    if (arg1 == 0) {
        if ((u32) (M2C_FIELD(arg0, s32 *, 0xEC) - 4) > 1U) {
            return;
        }
        if (arg2 == 1) {
            M2C_FIELD(arg0, s8 *, 0xE3) = 1;
        }
        func_0208e874(arg0, 1);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) & ~1);
}
