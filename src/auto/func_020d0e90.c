#include "m2c.h"

M2C_UNK func_020ce868(M2C_UNK);                     /* extern */
s32 func_020d0f60();                                /* extern */
M2C_UNK func_020d1240(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_020d128c(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK func_020d0e6c;

void func_020d0e90(void) {
    func_020d1240(7, &func_020d0e6c);
    if (func_020d0f60() == 0) {
        return;
    }
    if (func_020d128c(7, 1) != 0) {
        return;
    }
    do {
        func_020ce868(0x64);
    } while (func_020d128c(7, 1) == 0);
}
