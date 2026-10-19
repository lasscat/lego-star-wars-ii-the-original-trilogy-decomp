#include "m2c.h"

void WmClearFifoRecvFlag(void) {
    u16 temp_r0;

    temp_r0 = *(u16 *) 0x027FFF96;
    if (temp_r0 & 1) {
        *(u16 *) 0x027FFF96 = temp_r0 & ~1;
    }
}
