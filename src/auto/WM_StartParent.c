#include "m2c.h"

M2C_UNK WMi_StartParentEx(M2C_UNK, M2C_UNK);            /* extern */

void WM_StartParent(M2C_UNK arg0) {
    WMi_StartParentEx(arg0, 1);
}
