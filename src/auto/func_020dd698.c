#include "m2c.h"

s32 func_020dd6c0();                                /* extern */
s32 func_020dd6d8();                                /* extern */

s32 func_020dd698(void) {
    if ((func_020dd6d8() != 0) && (func_020dd6c0() == 0)) {
        return 1;
    }
    return 0;
}
