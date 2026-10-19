#include "m2c.h"

M2C_UNK OSi_DoUnlockByWord(M2C_UNK, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK OSi_FreeCartridgeBus;

void OS_UnlockCartridge(M2C_UNK arg0) {
    OSi_DoUnlockByWord(arg0, 0x027FFFE8, &OSi_FreeCartridgeBus, 1);
}
