#include "m2c.h"

M2C_UNK func_0208d244();                            /* extern */

void func_0208d218(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) != 0) {
        func_0208d244(arg0);
    }
    M2C_FIELD(arg0, u8 *, 0x38) = 1U;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
}
