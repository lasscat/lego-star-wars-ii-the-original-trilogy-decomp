#include "m2c.h"

M2C_UNK OS_Terminate();                            /* extern */
extern s16 CTRDGi_Work;

void CTRDGi_CallbackForInitModuleInfo(s32 arg0, s32 arg1) {
    if ((arg1 & 0x3F) == 1) {
        CTRDGi_Work = 1;
        return;
    }
    OS_Terminate();
}
