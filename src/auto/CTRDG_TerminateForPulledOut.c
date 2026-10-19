#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
M2C_UNK CTRDGi_SendtoPxi(M2C_UNK);                     /* extern */

void CTRDG_TerminateForPulledOut(void) {
    CTRDGi_SendtoPxi(2);
    OS_Terminate();
}
