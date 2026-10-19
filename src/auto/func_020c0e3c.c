#include "m2c.h"

extern M2C_UNK (*NNS_GfdDefaultFuncFreeTexVram)(s32);
extern M2C_UNK (*NNS_GfdDefaultFuncFreePlttVram)(s32);

void func_020c0e3c(void *arg0) {
    NNS_GfdDefaultFuncFreeTexVram(M2C_FIELD(arg0, s32 *, 0x48));
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        NNS_GfdDefaultFuncFreePlttVram(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    M2C_FIELD(arg0, s8 *, 0x15) = 0;
}
