#include "m2c.h"

M2C_UNK MI_StopDma(M2C_UNK);                     /* extern */
M2C_UNK MI_HBlankDmaCopy16(M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */

void func_02084b1c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xEB9) == 0) {
        return;
    }
    MI_StopDma(2);
    M2C_FIELD((void *) 0x04001040, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0xD38);
    M2C_FIELD((void *) 0x04001040, s16 *, 4) = 0xC0;
    MI_HBlankDmaCopy16(2, arg0 + 0xD3A, 0x04001040, 2);
}
