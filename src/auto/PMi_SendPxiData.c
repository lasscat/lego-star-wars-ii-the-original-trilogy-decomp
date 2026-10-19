#include "m2c.h"

s32 PXI_SendWordByFifo(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void PMi_SendPxiData(M2C_UNK arg0) {
    do {

    } while (PXI_SendWordByFifo(8, arg0, 0) != 0);
}
