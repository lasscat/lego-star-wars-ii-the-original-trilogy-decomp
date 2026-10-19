#include "m2c.h"

extern u16 data_02115758;

void OSi_SetTimerReserved(s32 arg0) {
    data_02115758 |= 1 << arg0;
}
