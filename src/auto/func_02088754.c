#include "m2c.h"

s32 func_02088754(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) - 1);
    if (M2C_FIELD(arg0, u16 *, 0xC) == 0) {
        return 1;
    }
    return 0;
}
