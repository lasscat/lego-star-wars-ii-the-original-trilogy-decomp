#include "m2c.h"

extern M2C_UNK data_02117e20;

s32 WMi_GetSystemWork(void) {
    return M2C_FIELD(&data_02117e20, s32 *, 4);
}
