#include "m2c.h"

M2C_UNK CARD_UnlockRom(u16);                         /* extern */
extern M2C_UNK mii_card_param;

void MIi_UnlockCard(void) {
    CARD_UnlockRom(M2C_FIELD(&mii_card_param, u16 *, 4));
}
