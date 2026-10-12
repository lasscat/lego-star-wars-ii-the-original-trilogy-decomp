#include "m2c.h"

M2C_UNK func_02026318();                            /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_02059988(M2C_UNK arg0, void *arg1) {
    if (func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1)) == 0) {
        return;
    }
    func_02026318();
}
