#include "m2c.h"

M2C_UNK func_020ca66c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02115376;

void func_020ca6a0(void) {
    *(s32 *) 0x04000000 &= ~0x40000000;
    func_020ca66c(&data_02115376);
}
