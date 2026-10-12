#include "m2c.h"

M2C_UNK func_020ca66c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_0211537e;

void func_020ca74c(void) {
    *(s32 *)0x04001000 &= ~0x40000000;
    func_020ca66c(&data_0211537e);
}
