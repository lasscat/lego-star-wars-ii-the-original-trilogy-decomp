#include "m2c.h"

M2C_UNK OS_SetIrqFunction(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK OS_EnableIrqMask(M2C_UNK);                     /* extern */
M2C_UNK OS_EnableInterrupts(M2C_UNK, u16);                /* extern */
extern M2C_UNK func_0205d1a0;

void func_0205d158(void) {
    u16 temp_r1;

    OS_SetIrqFunction(1, &func_0205d1a0);
    OS_EnableIrqMask(1);
    temp_r1             = *(u16 *) 0x04000208;
    *(u16 *) 0x04000208 = 1;
    OS_EnableInterrupts(1, temp_r1);
    *(s16 *) 0x04000004 = 8;
}
