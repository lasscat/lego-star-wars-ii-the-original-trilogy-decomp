#include "m2c.h"

extern M2C_UNK CARDi_IsPulledOutFlag;

void CARD_SetPulledOutCallback(s32 arg0) {
    M2C_FIELD(&CARDi_IsPulledOutFlag, s32 *, 4) = arg0;
}
