#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
M2C_UNK CTRDG_TerminateForPulledOut();                            /* extern */
extern M2C_UNK data_0211e460;

void CTRDGi_PulledOutCallback(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        if (M2C_FIELD(&data_0211e460, s32 *, 0xC) != 0) {
            return;
        }
        var_r0 = 0;
        if (M2C_FIELD(&data_0211e460, s32(**)(), 0x18) != NULL) {
            var_r0 = M2C_FIELD(&data_0211e460, s32(**)(), 0x18)();
        }
        if (var_r0 != 0) {
            CTRDG_TerminateForPulledOut();
        }
        M2C_FIELD(&data_0211e460, s32 *, 0xC) = 1;
        return;
    }
    OS_Terminate();
}
