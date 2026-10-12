#include "m2c.h"

extern M2C_UNK (*data_021012f0)(s32);
extern M2C_UNK (*data_021012f8)(s32);

void func_020c0e3c(void *arg0) {
    data_021012f0(M2C_FIELD(arg0, s32 *, 0x48));
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        data_021012f8(M2C_FIELD(arg0, s32 *, 0x4C));
    }
    M2C_FIELD(arg0, s8 *, 0x15) = 0;
}
