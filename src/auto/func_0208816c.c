#include "m2c.h"

s32 func_02054da8();                                /* extern */
M2C_UNK func_02055b64(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0205ab58(s32);                         /* extern */

void func_0208816c(void) {
    func_0205ab58(0x593);
    func_02055b64(func_02054da8() + 0xC0, 0x60, 0x60, 1);
}
