#include "m2c.h"

s32 CTRDGi_IsAgbCartridgeAtInit();                                /* extern */
s32 CTRDG_IsExisting();                                /* extern */

s32 CTRDG_IsOptionCartridge(void) {
    if ((CTRDG_IsExisting() != 0) && (CTRDGi_IsAgbCartridgeAtInit() == 0)) {
        return 1;
    }
    return 0;
}
