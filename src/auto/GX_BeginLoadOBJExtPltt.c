#include "m2c.h"

s32 GX_ResetBankForOBJExtPltt();                                /* extern */
extern M2C_UNK sSubBGExtPltt;

void GX_BeginLoadOBJExtPltt(void) {
    s32 temp_r0;

    temp_r0                             = GX_ResetBankForOBJExtPltt();
    M2C_FIELD(&sSubBGExtPltt, s32 *, 8) = temp_r0;
    switch (temp_r0) {                              /* irregular */
        case 0x0:
            return;
        case 0x40:
            M2C_FIELD(&sSubBGExtPltt, s32 *, 4) = 0x06894000;
            return;
        case 0x20:
            M2C_FIELD(&sSubBGExtPltt, s32 *, 4) = 0x06890000;
            return;
    }
}
