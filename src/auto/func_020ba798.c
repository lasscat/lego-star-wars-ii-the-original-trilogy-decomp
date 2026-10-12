#include "m2c.h"

M2C_UNK func_020ba7e0();                            /* extern */
s32 func_020d2cbc(M2C_UNK *, s32, M2C_UNK);         /* extern */
extern M2C_UNK data_0210db88;

s32 func_020ba798(s32 arg0, M2C_UNK arg1) {
    if (func_020d2cbc(&data_0210db88, arg0, arg1) < 0) {
        func_020ba7e0();
    }
    return arg0;
}
