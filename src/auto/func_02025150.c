#include "m2c.h"

void func_02025150(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x212) == 0x2B) {
        M2C_FIELD(arg0, s8 *, 0x232) = 1;
    }
}
