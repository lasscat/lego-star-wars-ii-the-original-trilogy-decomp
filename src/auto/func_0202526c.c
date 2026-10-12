#include "m2c.h"

M2C_UNK func_02011384();                            /* extern */
M2C_UNK func_0202532c(void *);                      /* extern */
extern M2C_UNK data_020fda18;

void *func_0202526c(void *arg0, s32 arg1) {
    func_02011384();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fda18;
    M2C_FIELD(arg0, s32 *, 0x21C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1BC) = 0;
    if (arg1 != 0x161) {
        func_0202532c(arg0);
    }
    return arg0;
}
