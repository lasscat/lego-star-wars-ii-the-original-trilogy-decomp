#include "m2c.h"

M2C_UNK DC_InvalidateRange(void *, M2C_UNK);             /* extern */
extern void *SNDi_SharedWork;

u16 SND_GetChannelStatus(void) {
    DC_InvalidateRange(SNDi_SharedWork + 8, 2);
    return M2C_FIELD(SNDi_SharedWork, u16 *, 8);
}
