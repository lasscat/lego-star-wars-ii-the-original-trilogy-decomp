#include "m2c.h"

M2C_UNK func_020556e0(void *);                      /* extern */
M2C_UNK func_0205df00(void *, M2C_UNK);             /* extern */

void *func_0205569c(void *arg0) {
    func_0205df00(arg0, 0x40);
    M2C_FIELD(arg0, s8 *, 0x20) = 3;
    func_020556e0(arg0);
    return arg0;
}
