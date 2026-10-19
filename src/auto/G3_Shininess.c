#include "m2c.h"

M2C_UNK GX_SendFifo128B();                            /* extern */

void G3_Shininess(s32 arg0) {
    *(s32 *) 0x04000400 = 0x34;
    GX_SendFifo128B(arg0);
}
