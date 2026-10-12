#include "m2c.h"

M2C_UNK func_020cc9c0(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_020ccb04(M2C_UNK);                     /* extern */
M2C_UNK func_020ce7f0(M2C_UNK, u16);                /* extern */
extern M2C_UNK func_0205d1a0;

void func_0205d158(void) {
    u16 temp_r1;

    func_020cc9c0(1, &func_0205d1a0);
    func_020ccb04(1);
    temp_r1 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 1;
    func_020ce7f0(1, temp_r1);
    *(s16 *)0x04000004 = 8;
}
