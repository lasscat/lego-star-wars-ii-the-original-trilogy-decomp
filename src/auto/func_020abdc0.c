#include "m2c.h"

s32 func_02064f7c();                                /* extern */
M2C_UNK func_020653d4(M2C_UNK);                     /* extern */

s32 func_020abdc0(M2C_UNK arg0) {
    if (func_02064f7c() != 0) {
        return 0;
    }
    func_020653d4(arg0);
    return 1;
}
