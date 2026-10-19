#include "m2c.h"

M2C_UNK OSi_DoTryLockByWord(M2C_UNK, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK OSi_AllocateCartridgeBus;

void OS_TryLockCartridge(M2C_UNK arg0) {
    OSi_DoTryLockByWord(arg0, 0x027FFFE8, &OSi_AllocateCartridgeBus, 1);
}
