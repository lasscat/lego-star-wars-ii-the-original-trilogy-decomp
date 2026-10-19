#include "m2c.h"

M2C_UNK RtcSendPxiCommand(M2C_UNK);                     /* extern */

void RTCi_ReadRawTimeAsync(void) {
    RtcSendPxiCommand(0x12);
}
