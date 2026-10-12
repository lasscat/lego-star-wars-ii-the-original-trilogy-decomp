#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
extern M2C_UNK data_0210b320;

void func_020aeea8(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4();
    }
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 9;
}
