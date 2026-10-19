#include "m2c.h"

s32 OS_ReceiveMessage(M2C_UNK *, u16 **, M2C_UNK);      /* extern */
M2C_UNK OS_JamMessage(M2C_UNK *, u16 *, M2C_UNK);   /* extern */
M2C_UNK DC_InvalidateRange(u16 *, M2C_UNK);              /* extern */
extern M2C_UNK bufMsgQ;

u16 *WmGetCommandBuffer4Arm7(void) {
    u16 *sp0;

    if (OS_ReceiveMessage(&bufMsgQ, &sp0, 0) == 0) {
        return NULL;
    }
    DC_InvalidateRange(sp0, 2);
    if (*sp0 & 0x8000) {
        return sp0;
    }
    OS_JamMessage(&bufMsgQ, sp0, 1);
    return NULL;
}
