#include "m2c.h"
s32 func_02067b54(s32);

s32 func_020a6e98(void *arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(arg0, u8 *, 0x241) == 0) {
        if ((arg1 == 0) || (arg2 == 0)) {
            return 0;
        }
        if ((arg1 == (func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C)) - 1)) ||
            (arg2 == (func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C)) - 1))) {
            return 0;
        }
    }
    return 1;
}
