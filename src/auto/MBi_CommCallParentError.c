#include "m2c.h"

M2C_UNK MBi_CommChangeParentStateCallbackOnly(M2C_UNK, M2C_UNK, s16 *);     /* extern */

void MBi_CommCallParentError(M2C_UNK arg0, s16 arg1) {
    s16 sp0;

    sp0 = arg1;
    MBi_CommChangeParentStateCallbackOnly(arg0, 0xD, &sp0);
}
