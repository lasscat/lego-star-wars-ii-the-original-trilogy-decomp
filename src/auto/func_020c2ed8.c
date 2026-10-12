#include "m2c.h"

u16 func_020c2ba4(void *, u16);                     /* extern */
s32 func_020c2bc4();                                /* extern */

s32 func_020c2ed8(void *arg0) {
    if (func_020c2bc4() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, u16 *, 0xA) = func_020c2ba4(arg0, M2C_FIELD(arg0, u16 *, 0xA));
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) + 1);
    return 1;
}
