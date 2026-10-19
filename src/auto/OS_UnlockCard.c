#include "m2c.h"

M2C_UNK OS_UnlockByWord(M2C_UNK, s32, M2C_UNK *);     /* extern */
extern M2C_UNK OSi_FreeCardBus;

void OS_UnlockCard(M2C_UNK arg0) {
    OS_UnlockByWord(arg0, 0x027FFFE0, &OSi_FreeCardBus);
}
