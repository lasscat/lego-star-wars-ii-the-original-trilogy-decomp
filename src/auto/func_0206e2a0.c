#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0206e6cc(void *, s8);                  /* extern */

void func_0206e2a0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = 0x8C;
    M2C_FIELD(arg0, s8 *, 0x28)  = 3;
    M2C_FIELD(arg0, s8 *, 0x25)  = 0;
    func_0206574c(M2C_FIELD(arg0, s32 *, 0xC), 9, -1);
    func_0206e6cc(arg0, M2C_FIELD(arg0, s8 *, 0x25));
}
