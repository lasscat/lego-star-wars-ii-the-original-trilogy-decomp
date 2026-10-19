#include "m2c.h"

M2C_UNK NNS_G3dGlbInit();                            /* extern */
M2C_UNK G3X_Init();                            /* extern */

void NNS_G3dInit(void) {
    G3X_Init();
    NNS_G3dGlbInit();
    *(s32 *) 0x04000600 = (*(s32 *) 0x04000600 & ~0xC0000000) | 0x80000000;
}
