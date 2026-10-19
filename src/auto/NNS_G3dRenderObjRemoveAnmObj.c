#include "m2c.h"

s32 removeLink_();                    /* extern */

void NNS_G3dRenderObjRemoveAnmObj(s32 *arg0, M2C_UNK arg1) {
    if ((removeLink_(((s8 *) arg0 + 8)) == 0) && (removeLink_(((s8 *) arg0 + 0x10), arg1) == 0) &&
        (removeLink_(((s8 *) arg0 + 0x18), arg1) == 0)) {
        return;
    }
    *arg0 |= 0x10;
}
