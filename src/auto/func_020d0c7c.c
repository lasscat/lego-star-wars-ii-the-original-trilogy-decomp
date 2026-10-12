#include "m2c.h"

s32 func_020d094c();                         /* extern */
s32 func_020d0d88();                         /* extern */
M2C_UNK func_020d0ef0();                            /* extern */

void func_020d0c7c(M2C_UNK arg0) {
    if (func_020d0d88() != 0) {
        return;
    }
    do {

    } while (func_020d094c(0) != 0);
    if (func_020d0d88(arg0) != 0) {
        return;
    }
    func_020d0ef0();
    if (func_020d0d88(arg0) != 0) {
        return;
    }
    do {
        func_020d094c(1);
    } while (func_020d0d88(arg0) == 0);
}
