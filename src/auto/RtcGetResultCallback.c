#include "m2c.h"

extern M2C_UNK RTCi_Bss;

void RtcGetResultCallback(s32 arg0) {
    M2C_FIELD(&RTCi_Bss, s32 *, 0x24) = arg0;
}
