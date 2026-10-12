#include "m2c.h"

M2C_UNK func_02096278();                            /* extern */
extern M2C_UNK data_020ff958;

void *func_02098240(void *arg0) {
    func_02096278();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff958;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0xB;
    M2C_FIELD(arg0, s32 *, 0x2C) = -1;
    return arg0;
}
