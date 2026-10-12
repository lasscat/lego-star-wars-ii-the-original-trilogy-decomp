#include "m2c.h"

M2C_UNK func_020185b4();                            /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */

void func_02018658(void *arg0) {
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    if (arg0 == NULL) {
        return;
    }
    func_020185b4(arg0);
    func_0205e84c(arg0);
}
