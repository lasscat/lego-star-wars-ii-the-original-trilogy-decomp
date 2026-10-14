#include "m2c.h"

M2C_UNK func_0205d568();                            /* extern */
extern M2C_UNK data_020fe614;

void *func_0205d378(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe614;
    M2C_FIELD(arg0, s32 *, 0x10)   = arg1;
    func_0205d568();
    return arg0;
}
