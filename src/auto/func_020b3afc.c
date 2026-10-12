#include "m2c.h"

M2C_UNK func_020b37c0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b3998(void *, M2C_UNK);             /* extern */

void func_020b3afc(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x3E) = 1;
    func_020b37c0(arg0, 5);
    func_020b3998(arg0, 5);
}
