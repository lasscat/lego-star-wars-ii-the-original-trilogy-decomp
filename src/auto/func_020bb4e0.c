#include "m2c.h"

M2C_UNK func_020b45ac(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210db84;

void func_020bb4e0(s8 arg0) {
    M2C_FIELD(&data_0210db84, s8 *, 0xC0) = arg0;
    func_020b45ac(4);
}
