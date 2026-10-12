#include "m2c.h"

extern M2C_UNK data_020fec75;

s32 func_0202fb90(void *arg0, s32 arg1) {
    if (arg1 & ((u8 *)&data_020fec75)[(M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x6BB) * 0xC)]) {
        return 1;
    }
    return 0;
}
