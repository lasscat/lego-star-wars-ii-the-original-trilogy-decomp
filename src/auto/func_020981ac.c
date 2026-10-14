#include "m2c.h"

M2C_UNK func_02096278();                            /* extern */
extern M2C_UNK data_020ff940;

void *func_020981ac(void *arg0) {
    func_02096278();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff940;
    M2C_FIELD(arg0, s8 *, 0x2C)    = 0;
    M2C_FIELD(arg0, s8 *, 0x2D)    = 0;
    M2C_FIELD(arg0, s8 *, 0x2E)    = 0;
    return arg0;
}
