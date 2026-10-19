#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
s32 CARD_IsEnabled();                                /* extern */

void CARD_CheckEnabled(void) {
    if (CARD_IsEnabled() != 0) {
        return;
    }
    OS_Terminate();
}
