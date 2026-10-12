#include "m2c.h"

s32 func_01ffa41c(M2C_UNK);                         /* extern */
M2C_UNK func_01ffa430(void *, M2C_UNK);             /* extern */

void func_0205c008(void *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = func_01ffa41c(arg1);
    M2C_FIELD(arg0, s32 *, 0x10) = func_01ffa41c(arg1);
    func_01ffa430(arg0, arg1);
}
