#include "m2c.h"

s32 PXI_SendWordByFifo(M2C_UNK, s32, M2C_UNK);           /* extern */

s32 RtcSendPxiCommand(s32 arg0) {
    if (PXI_SendWordByFifo(5, (arg0 << 8) & 0x7F00, 0) >= 0) {
        return 1;
    }
    return 0;
}
