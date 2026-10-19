#include "m2c.h"

extern M2C_UNK CARDi_ReadCard;

M2C_UNK *CARDi_GetRomAccessor(void) {
    return &CARDi_ReadCard;
}
