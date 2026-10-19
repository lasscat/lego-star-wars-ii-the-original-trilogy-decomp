/* Reconstructed from USA ARM9 at 0x020cf624 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s16 func_020ccec8();                                /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
extern M2C_UNK mii_card_param;

void MIi_InitCard(void) {
    s32 *temp_r4;
    s16 temp_r0;
    s32 temp_r5;

    temp_r4 = (s32 *) &mii_card_param;
    temp_r5 = OS_DisableInterrupts();
    if (temp_r4[0] == 0) {
        temp_r0                      = func_020ccec8();
        temp_r4[0]                   = 1;
        M2C_FIELD(temp_r4, s16 *, 4) = temp_r0;
    }
    OS_RestoreInterrupts(temp_r5);
}
