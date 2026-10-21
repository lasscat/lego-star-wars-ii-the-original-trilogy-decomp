#include "m2c.h"

extern M2C_UNK data_0210a0b4;
extern s32 func_020abeac(void *, void *);

s32 func_020ab614(void *arg0, void *arg1) {
    s32 res;

    if (M2C_FIELD(arg0, u16 *, 0x14) & 1) {
        M2C_FIELD(arg0, u16 *, 0x14) &= ~3;
    }
    res                         = func_020abeac(&data_0210a0b4, M2C_FIELD(arg1, void **, 0));
    M2C_FIELD(arg1, void **, 0) = NULL;
    return res;
}
