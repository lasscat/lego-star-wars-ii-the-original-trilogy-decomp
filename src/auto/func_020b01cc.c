#include "m2c.h"

extern M2C_UNK data_021007ac;

u16 func_020b01cc(s32 arg0) {
    return M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_021007ac + (arg0 * 4))), u16 *, 0);
}
