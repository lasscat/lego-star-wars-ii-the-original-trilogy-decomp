#include "m2c.h"
s32 func_020363b0(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x30) != 6 || M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        return 5;
    }
    if (M2C_FIELD(arg0, s32 *, 0x54) == 0) {
        M2C_FIELD(arg0, s32 *, 0x54) = arg1;
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        M2C_FIELD(arg0, s32 *, 0x58) = arg1;
        return 1;
    }
    return 5;
}
