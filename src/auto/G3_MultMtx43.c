#include "m2c.h"

M2C_UNK GX_SendFifo48B();                            /* extern */

void G3_MultMtx43(s32 arg0) {
    *(s32 *) 0x04000400 = 0x19;
    GX_SendFifo48B(arg0);
}
