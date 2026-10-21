/* Reconstructed from USA ARM9 at 0x020cf694 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef volatile u32 vu32;

extern void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
extern void MIi_CheckDma0SourceAddress(s32 dmaNo, s32 src, s32 size, s32 type);
extern void MIi_DmaSetParams(u32 dmaNo, u32 src, u32 dest, u32 cnt);

void MIi_CardDmaCopy32(u32 dmaNo, u32 src, u32 dest, u32 size) {
    MIi_CheckAnotherAutoDMA(dmaNo, (u32) -1);
    MIi_CheckDma0SourceAddress(dmaNo, src, size, 0x01000000);
    if (size == 0) {
        return;
    }
    {
        /* DMA channel control register: 0x040000B0 + 0xC * dmaNo (word index 3 * n + 2). */
        vu32 *cnt = &(((vu32 *) 0x040000B0)[dmaNo * 3 + 2]);
        while ((*cnt & 0x80000000) != 0) {
        }
        MIi_DmaSetParams(dmaNo, src, dest, 0xAF000001);
    }
}
