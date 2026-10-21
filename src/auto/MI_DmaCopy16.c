#include "m2c.h"

/* MIi_CheckDma0SourceAddress(dmaId, src, size, 0) */
M2C_UNK MIi_CheckDma0SourceAddress(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */
/* MIi_DmaSetParams variant used by the 16-bit copy path */
void func_01ffd4c8(M2C_UNK, M2C_UNK, M2C_UNK, u32); /* extern */

void MI_DmaCopy16(s32 ch, M2C_UNK src, M2C_UNK dst, u32 len) {
    volatile u32 *cnt;
    if (len == 0) {
        return;
    }
    MIi_CheckDma0SourceAddress(ch, src, len, 0);
    /* DMA channel control register */
    cnt = (volatile u32 *) (0x4000000 + ((ch * 3 + 2) * 4 + 0xb0));
    while (*cnt & 0x80000000) {
    }
    func_01ffd4c8(ch, src, dst, (len >> 1) | 0x80000000);
    while (*cnt & 0x80000000) {
    }
}
