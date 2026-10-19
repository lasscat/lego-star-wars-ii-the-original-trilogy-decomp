#include "m2c.h"

s32 GX_ResetBankForSubOBJExtPltt();                                /* extern */
extern M2C_UNK sSubBGExtPltt;

void GXS_BeginLoadOBJExtPltt(void) {
    M2C_FIELD(&sSubBGExtPltt, s32 *, 0x18) = GX_ResetBankForSubOBJExtPltt();
}
