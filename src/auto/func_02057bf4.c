#include "m2c.h"

M2C_UNK func_020a0418(s32, s32, M2C_UNK);           /* extern */
s32 func_020aaeb4();                                /* extern */

void func_02057bf4(void *arg0, u8 *arg1) {
    func_020a0418(func_020aaeb4(), M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x38) + (*arg1 * 8), 1);
}
