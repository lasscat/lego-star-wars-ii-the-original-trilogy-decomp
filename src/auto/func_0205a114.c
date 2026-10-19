#include "m2c.h"

extern M2C_UNK (*NNS_GfdDefaultFuncFreeTexVram)(s32);

void func_0205a114(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 9) == 0) {
        return;
    }
    NNS_GfdDefaultFuncFreeTexVram(M2C_FIELD(arg0, s32 *, 0x10));
    M2C_FIELD(arg0, u8 *, 9) = 0U;
}
