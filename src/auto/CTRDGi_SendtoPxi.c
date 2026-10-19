#include "m2c.h"

M2C_UNK WaitByLoop(M2C_UNK);                        /* extern */
s32 PXI_SendWordByFifo(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void CTRDGi_SendtoPxi(M2C_UNK arg0) {
    if (PXI_SendWordByFifo(0xD, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (PXI_SendWordByFifo(0xD, arg0, 0) != 0);
}
