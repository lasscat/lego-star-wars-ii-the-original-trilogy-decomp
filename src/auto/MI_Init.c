#include "m2c.h"

M2C_UNK MI_SetWramBank(M2C_UNK);                     /* extern */
M2C_UNK MI_StopDma(M2C_UNK);                     /* extern */

void MI_Init(void) {
    MI_SetWramBank(3);
    MI_StopDma(0);
}
