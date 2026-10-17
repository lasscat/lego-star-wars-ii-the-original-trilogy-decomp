#include "m2c.h"

u8 func_02083340(void *arg0, s32 arg1) {
    if (arg1 == -1) {
        return 0x26U;
    }
    return *(s8 *) (M2C_FIELD(arg0, s32 *, 0x15C) + arg1);
}