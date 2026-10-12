#include "m2c.h"

M2C_UNK func_02055108(void *);                      /* extern */
M2C_UNK func_0205df00(void *, M2C_UNK);             /* extern */

void *func_020550c4(void *arg0) {
    func_0205df00(arg0, 0x40);
    M2C_FIELD(arg0, s8 *, 0x20) = 3;
    func_02055108(arg0);
    return arg0;
}
