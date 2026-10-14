#include "m2c.h"

s32 func_02025168(void *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0x1BC) == 1) && (M2C_FIELD(arg0, u8 *, 0x236) == 0)) {
        M2C_FIELD(arg0, u8 *, 0x1BC)  = 2U;
        M2C_FIELD(arg0, u8 *, 0x236)  = 2U;
        M2C_FIELD(arg0, s32 *, 0x238) = arg1;
        return 1;
    }
    return 0;
}
