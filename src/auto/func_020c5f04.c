#include "m2c.h"

M2C_UNK func_020c40e0();                            /* extern */
M2C_UNK func_020cae14();                            /* extern */

void func_020c5f04(void) {
    func_020cae14();
    func_020c40e0();
    *(s32 *) 0x04000600 = (*(s32 *) 0x04000600 & ~0xC0000000) | 0x80000000;
}
