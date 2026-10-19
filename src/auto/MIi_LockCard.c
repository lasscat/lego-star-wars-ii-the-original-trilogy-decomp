#include "m2c.h"

M2C_UNK MIi_InitCard();                            /* extern */
M2C_UNK CARD_LockRom(u16);                         /* extern */
extern M2C_UNK mii_card_param;

void MIi_LockCard(void) {
    MIi_InitCard();
    CARD_LockRom(M2C_FIELD(&mii_card_param, u16 *, 4));
}
