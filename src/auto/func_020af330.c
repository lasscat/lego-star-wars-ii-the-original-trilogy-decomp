#include "m2c.h"

M2C_UNK func_020af3e4();                            /* extern */
M2C_UNK func_020af42c(void *);                      /* extern */
s32 func_020af460(void *);                          /* extern */
s32 func_020af594(void *);                          /* extern */

s32 func_020af330(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x6F4) != 0) {
        func_020af3e4(arg0);
    }
    func_020af42c(arg0);
    if (func_020af594(arg0) == 0) {
        return 1;
    }
    if ((M2C_FIELD(arg0, u8 *, 0x6F4) != 0) && (func_020af460(arg0) == 0)) {
        return 2;
    }
    return 0;
}
