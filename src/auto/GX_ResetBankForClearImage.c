#include "m2c.h"

M2C_UNK resetBankForX_(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02115374;

void GX_ResetBankForClearImage(void) {
    resetBankForX_(&data_02115374);
}
