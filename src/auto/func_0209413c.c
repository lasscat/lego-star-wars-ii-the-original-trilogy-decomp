#include "m2c.h"

M2C_UNK func_02094088(void *, M2C_UNK, M2C_UNK, u8); /* extern */
extern M2C_UNK data_020ff7a4;

void *func_0209413c(void *arg0, s8 arg1, M2C_UNK arg2, M2C_UNK arg3, u8 arg4) {
    func_02094088(arg0, arg2, arg3, arg4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff7a4;
    M2C_FIELD(arg0, s8 *, 9) = arg1;
    return arg0;
}
