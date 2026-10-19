#include "m2c.h"

M2C_UNK MBi_CallReset();                            /* extern */

void MBi_OnReset(void) {
    MBi_CallReset();
}
