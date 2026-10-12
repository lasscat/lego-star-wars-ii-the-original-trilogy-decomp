#include "m2c.h"

M2C_UNK func_020b973c();                            /* extern */
extern M2C_UNK data_020fe318;

void *func_0204657c(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe318;
    if (M2C_FIELD(arg0, s32 *, 0x20) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x20) = 0;
    }
    return arg0;
}
