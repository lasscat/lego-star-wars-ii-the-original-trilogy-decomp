#include "m2c.h"

M2C_UNK OS_LockCard(M2C_UNK);                     /* extern */
M2C_UNK CARDi_LockResource(M2C_UNK, M2C_UNK);            /* extern */

void CARD_LockRom(M2C_UNK arg0) {
    CARDi_LockResource(arg0, 1);
    OS_LockCard(arg0);
}
