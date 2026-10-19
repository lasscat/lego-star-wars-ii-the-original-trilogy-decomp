#include "m2c.h"

M2C_UNK OS_UnlockCard();                            /* extern */
M2C_UNK CARDi_UnlockResource(M2C_UNK, M2C_UNK);            /* extern */

void CARD_UnlockRom(M2C_UNK arg0) {
    OS_UnlockCard();
    CARDi_UnlockResource(arg0, 1);
}
