#include "m2c.h"

extern M2C_UNK data_0211e400;

u16 func_020dcde4(void) {
    return M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), u16 *, 0xC);
}
