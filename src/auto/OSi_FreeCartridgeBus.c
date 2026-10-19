#include "m2c.h"

void OSi_FreeCartridgeBus(void) {
    *(u16 *) 0x04000204 |= 0x80;
}
