#include "m2c.h"

extern M2C_UNK (*NNS_GfdDefaultFuncFreePlttVram)(s32);

void func_0205a9b8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        return;
    }
    NNS_GfdDefaultFuncFreePlttVram(M2C_FIELD(arg0, s32 *, 8));
    M2C_FIELD(arg0, u8 *, 0) = 0U;
}
