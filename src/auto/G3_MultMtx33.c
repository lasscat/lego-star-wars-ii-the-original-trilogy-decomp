#include "m2c.h"

M2C_UNK MI_Copy36B();                            /* extern */

void G3_MultMtx33(s32 arg0) {
    *(s32 *) 0x04000400 = 0x1A;
    MI_Copy36B(arg0);
}
