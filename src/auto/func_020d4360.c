#include "m2c.h"

s32 func_020d4360(void) {
    if (*(u16 *)0x04000304 & 1) {
        return 1;
    }
    return 0;
}
