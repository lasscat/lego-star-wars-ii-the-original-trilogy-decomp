#include "m2c.h"

s32 func_02088798(void *arg0, s32 arg1) {
    s32 var_r2;

    var_r2 = 4;
    switch (arg1) {                                 /* irregular */
        case 0:
            var_r2 = 0;
            break;
        case 1:
            var_r2 = 1;
            break;
        case 2:
            if (M2C_FIELD(arg0, u8 *, 0x14) != 0) {
                var_r2 = 3;
            } else {
                var_r2 = 2;
            }
            break;
    }
    return var_r2;
}
