#include "m2c.h"

M2C_UNK NNS_GfdInitVramTransferManager(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK OS_EnableIrqMask(M2C_UNK);                     /* extern */
M2C_UNK OS_DisableIrqMask(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210a10c;

void func_020ac680(void) {
    OS_DisableIrqMask(1);
    NNS_GfdInitVramTransferManager(&data_0210a10c, 0x20);
    OS_EnableIrqMask(1);
}
