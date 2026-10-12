#include "m2c.h"

M2C_UNK func_02096278();                            /* extern */
extern M2C_UNK data_020ff88c;

void *func_02096b78(void *arg0) {
    func_02096278();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff88c;
    M2C_FIELD(arg0, s8 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 1;
    return arg0;
}
