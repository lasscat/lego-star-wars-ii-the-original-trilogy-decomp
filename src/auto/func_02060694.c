#include "m2c.h"

M2C_UNK func_020c9848(M2C_UNK);                     /* extern */
M2C_UNK func_020ccb34(M2C_UNK);                     /* extern */

void func_02060694(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xC34) = 0;
    func_020c9848(0);
    func_020ccb34(2);
    *(u16 *) 0x04000004 &= ~0x10;
}
