#include "m2c.h"

void OS_SetArenaHi(s32 arg0, s32 arg1) {
    ((s32 *) (0x027FF000 + 0xDC4))[arg0] = arg1;
}
