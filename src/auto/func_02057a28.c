#include "m2c.h"

M2C_UNK func_020a0418(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_020a042c(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_020a9920();                            /* extern */
M2C_UNK func_020a99bc(void *, M2C_UNK);             /* extern */
void *func_020aaeb4();                              /* extern */

void func_02057a28(void *arg0, void *arg1) {
    s16 temp_r4;
    u8 temp_r6;

    func_020a99bc(func_020aaeb4(), 1);
    func_020aaeb4();
    func_020a9920();
    M2C_FIELD(func_020aaeb4(), s32 *, 0x220) = 0;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x21C) = 0;
    temp_r6                                  = M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(func_020aaeb4(), u8 *, 0x241)  = temp_r6;
    func_020a0418(func_020aaeb4(), M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x38) + (M2C_FIELD(arg1, u8 *, 3) * 8), 1);
    temp_r4 = M2C_FIELD(arg1, s16 *, 0);
    if ((s32) temp_r4 <= 0) {
        return;
    }
    func_020a042c(func_020aaeb4(), M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x38) + (temp_r4 * 8), 1);
}
