#include "m2c.h"

M2C_UNK NNS_FndAllocFromAllocator(M2C_UNK, s32);                /* extern */
s32 NNS_G3dAnmObjCalcSizeRequired(M2C_UNK, M2C_UNK);                /* extern */

void NNS_G3dAllocAnmObj(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    NNS_FndAllocFromAllocator(arg0, NNS_G3dAnmObjCalcSizeRequired(arg1, arg2));
}
