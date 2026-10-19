#include "m2c.h"

extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *);

s32 func_020653d4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xC) & 1) {
        if (M2C_FIELD(arg0, void **, 0) != 0) {
            NNS_GfdDefaultFuncFreeTexVram(M2C_FIELD(arg0, void **, 0));
        }
        if (M2C_FIELD(arg0, void **, 4) != 0) {
            NNS_GfdDefaultFuncFreeTexVram(M2C_FIELD(arg0, void **, 4));
        }
        if (M2C_FIELD(arg0, void **, 8) != 0) {
            NNS_GfdDefaultFuncFreePlttVram(M2C_FIELD(arg0, void **, 8));
        }
        M2C_FIELD(arg0, s32 *, 0) = 0;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
    M2C_FIELD(arg0, u8 *, 0xC) = 0U;
    return 1;
}
