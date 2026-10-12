#include "m2c.h"

M2C_UNK func_020d1450(void *, s32);                 /* extern */
s32 func_020d14ac(void *, s32);                     /* extern */
s32 func_020d2088(s32);                             /* extern */
M2C_UNK func_020d229c();                            /* extern */

s32 func_020d2330(void *arg0) {
    func_020d1450(arg0, func_020d14ac(arg0, M2C_FIELD(arg0, s32 *, 0x10)));
    if (func_020d2088(M2C_FIELD(arg0, s32 *, 8)) != 0) {
        func_020d229c();
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        return 1;
    }
    return 0;
}
