#include "m2c.h"

M2C_UNK CARDi_LockResource(M2C_UNK, M2C_UNK);            /* extern */

void CARD_LockBackup(M2C_UNK arg0) {
    CARDi_LockResource(arg0, 2);
}
