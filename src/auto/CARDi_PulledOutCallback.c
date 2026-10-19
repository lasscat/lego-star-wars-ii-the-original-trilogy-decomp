#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
M2C_UNK Card_HaltAfterRemoval();                            /* extern */
extern M2C_UNK CARDi_IsPulledOutFlag;

void CARDi_PulledOutCallback(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        if (M2C_FIELD(&CARDi_IsPulledOutFlag, s32 *, 0) != 0) {
            return;
        }
        var_r0                                      = 1;
        M2C_FIELD(&CARDi_IsPulledOutFlag, s32 *, 0) = 1;
        if (M2C_FIELD(&CARDi_IsPulledOutFlag, s32(**)(), 4) != NULL) {
            var_r0 = M2C_FIELD(&CARDi_IsPulledOutFlag, s32(**)(), 4)();
        }
        if (var_r0 == 0) {
            return;
        }
        Card_HaltAfterRemoval();
        return;
    }
    OS_Terminate();
}
