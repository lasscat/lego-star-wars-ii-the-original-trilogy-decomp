/* Reconstructed from USA ARM9 at 0x020ceb20 (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef volatile u32 vu32;

M2C_UNK MIi_CheckDma0SourceAddress(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */
M2C_UNK func_01ffd4c8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);          /* extern */

/* DMA channel registers start at 0x040000B0, three words per channel
 * (SAD, DAR, CNT); CNT is the third word of the channel. */
#define REG_DMA_CNT(chan) (*(vu32 *) (0x040000B0 + ((chan) * 3 + 2) * 4))

void MI_DmaCopy32(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, u32 arg3) {
    MIi_CheckDma0SourceAddress(arg0, arg1, arg3, 0);
    if (arg3 == 0) {
        return;
    }
    while (REG_DMA_CNT(arg0) & 0x80000000) {
    }
    func_01ffd4c8(arg0, arg1, arg2, (arg3 >> 2) | 0x84000000);
    while (REG_DMA_CNT(arg0) & 0x80000000) {
    }
}
