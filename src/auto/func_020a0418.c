#include "m2c.h"

M2C_UNK func_020a99a8();                            /* extern */

void func_020a0418(void *arg0, s32 arg1, s8 arg2) {
    M2C_FIELD(arg0, s32 *, 0x21C) = arg1;
    M2C_FIELD(arg0, s8 *, 0x23D)  = arg2;
    func_020a99a8();
}
