#include "m2c.h"

extern s32 *NNS_G3dGeBuffer;

void NNS_G3dGeSetBuffer(s32 *arg0) {
    if (NNS_G3dGeBuffer == NULL) {
        *arg0           = 0;
        NNS_G3dGeBuffer = arg0;
    }
}
