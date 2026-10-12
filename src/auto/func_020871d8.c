#include "m2c.h"

void func_020871d8(void *arg0, s8 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x2BB6) == 0) {
        M2C_FIELD(arg0, s8 *, 0x4560) = arg1;
    }
}
