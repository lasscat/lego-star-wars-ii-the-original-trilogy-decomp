#include "m2c.h"

M2C_UNK func_02064f90();                            /* extern */

void func_02064fa0(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 8);
    func_02064f90();
}
