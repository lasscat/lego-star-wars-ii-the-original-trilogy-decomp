#include "m2c.h"

M2C_UNK OSi_IrqCallback(M2C_UNK);                     /* extern */

void OSi_IrqDma2(void) {
    OSi_IrqCallback(2);
}
