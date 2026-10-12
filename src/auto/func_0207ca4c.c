#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(void *, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
M2C_UNK func_0207d094(void *, M2C_UNK);             /* extern */

void func_0207ca4c(void *arg0) {
    func_0206574c(arg0 + 0x70, 9, -1);
    M2C_FIELD(arg0, s32 *, 0xA0) = (s32) (M2C_FIELD(arg0, s32 *, 0xA0) + 1);
    M2C_FIELD(arg0, s32 *, 0xA0) = func_02065be8(arg0 + 0x70, M2C_FIELD(arg0, s32 *, 0xA0), 0x80, 0x38, func_02066708(0x153), 1);
    func_0207d094(arg0, 0);
}
