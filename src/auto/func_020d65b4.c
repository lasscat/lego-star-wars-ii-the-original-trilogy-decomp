#include "m2c.h"

extern u16 data_02117e20;

s32 func_020d65b4(void) {
    if (data_02117e20 != 0) {
        return 0;
    }
    return 3;
}
