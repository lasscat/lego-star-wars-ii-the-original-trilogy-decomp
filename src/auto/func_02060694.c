#include "m2c.h"

M2C_UNK GX_HBlankIntr(M2C_UNK);                     /* extern */
M2C_UNK OS_DisableIrqMask(M2C_UNK);                     /* extern */

void func_02060694(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xC34) = 0;
    GX_HBlankIntr(0);
    OS_DisableIrqMask(2);
    *(u16 *) 0x04000004 &= ~0x10;
}
