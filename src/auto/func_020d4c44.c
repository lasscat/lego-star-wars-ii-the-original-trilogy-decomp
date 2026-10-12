#include "m2c.h"

s32 func_020d12b0(M2C_UNK, s32, M2C_UNK);           /* extern */

s32 func_020d4c44(s32 arg0) {
    if (func_020d12b0(5, (arg0 << 8) & 0x7F00, 0) >= 0) {
        return 1;
    }
    return 0;
}
