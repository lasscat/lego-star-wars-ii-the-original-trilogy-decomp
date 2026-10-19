#include "m2c.h"

M2C_UNK CARDi_UnlockResource(M2C_UNK, M2C_UNK);            /* extern */

void CARD_UnlockBackup(M2C_UNK arg0) {
    CARDi_UnlockResource(arg0, 2);
}
