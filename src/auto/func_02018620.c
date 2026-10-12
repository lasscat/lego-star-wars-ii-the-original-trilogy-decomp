#include "m2c.h"

M2C_UNK func_020185b4();                            /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */

void func_02018620(void *arg0) {
    M2C_FIELD(arg0, u16 *, 4) = (u16) (M2C_FIELD(arg0, u16 *, 4) - 1);
    if (M2C_FIELD(arg0, u16 *, 4) != 0) {
        return;
    }
    if (arg0 == NULL) {
        return;
    }
    func_020185b4(arg0);
    func_0205e84c(arg0);
}
