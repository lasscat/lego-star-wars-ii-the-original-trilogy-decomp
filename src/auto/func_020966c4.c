#include "m2c.h"

M2C_UNK func_020966e8();                            /* extern */

void func_020966c4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) != 0) {
        func_020966e8(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38) = 1U;
}
