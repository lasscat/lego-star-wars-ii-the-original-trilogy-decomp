#include "m2c.h"

M2C_UNK func_020baef0();                            /* extern */

void func_020baedc(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 5) = arg1;
    M2C_FIELD(arg0, s8 *, 4) = arg2;
    func_020baef0();
}
