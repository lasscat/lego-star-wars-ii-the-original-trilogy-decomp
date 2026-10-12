#include "m2c.h"

s32 func_020917b4(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210930c;

s32 func_02068780(void) {
    if ((func_020917b4(&data_0210930c) >= 9) && (func_020917b4(&data_0210930c) <= 0xE)) {
        return 0;
    }
    return 1;
}
