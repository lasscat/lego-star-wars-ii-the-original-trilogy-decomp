#include "m2c.h"

s32 PXI_SendWordByFifo(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void RequestCommandProc(void) {
    do {

    } while (PXI_SendWordByFifo(7, 0, 0) < 0);
}
