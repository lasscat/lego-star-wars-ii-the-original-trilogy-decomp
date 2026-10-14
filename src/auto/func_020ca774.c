#include "m2c.h"

M2C_UNK func_020ca66c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02115380;

void func_020ca774(void) {
    *(s32 *) 0x04001000 &= ~0x80000000;
    func_020ca66c(&data_02115380);
}
