#include "m2c.h"

M2C_UNK func_0204a1c4(void *);                      /* extern */
M2C_UNK func_02059e14();                            /* extern */

void *func_0204a18c(void *arg0) {
    func_02059e14();
    M2C_FIELD(arg0, s8 *, 0xB)  = 3;
    M2C_FIELD(arg0, s8 *, 0xC)  = 4;
    M2C_FIELD(arg0, s8 *, 0xD)  = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    func_0204a1c4(arg0);
    return arg0;
}
