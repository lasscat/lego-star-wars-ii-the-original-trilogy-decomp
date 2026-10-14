#include "m2c.h"

s32 func_020d65b4();                                /* extern */

u16 func_020d6e4c(void) {
    if (func_020d65b4() != 0) {
        return 0x8000U;
    }
    return *(u16 *) 0x027FFCFA;
}
