#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
M2C_UNK PM_ForceToPowerOff(s32);                         /* extern */
M2C_UNK Card_PushRemovalTagWord(M2C_UNK, M2C_UNK);            /* extern */

void Card_HaltAfterRemoval(void) {
    s32 temp_r0;

    temp_r0 = (s32) (*(u16 *) 0x027FFFA8 & 0x8000) >> 0xF;
    if (temp_r0 != 0) {
        PM_ForceToPowerOff(temp_r0);
    }
    Card_PushRemovalTagWord(1, 1);
    OS_Terminate();
}
