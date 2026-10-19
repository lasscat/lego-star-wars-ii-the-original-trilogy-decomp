#include "m2c.h"

M2C_UNK resetBankForX_(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02115380;

void GX_ResetBankForSubOBJExtPltt(void) {
    *(s32 *) 0x04001000 &= ~0x80000000;
    resetBankForX_(&data_02115380);
}
