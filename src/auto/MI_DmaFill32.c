#include "m2c.h"

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void MIi_DmaSetParams_wait_noInt(u32 dmaNo, void *src, void *dest, u32 cnt);

void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size) {
    volatile u32 *cnt;
    u32 flags;

    if (size == 0) {
        return;
    }
    cnt = (volatile u32 *) (0x4000000 + ((dmaNo * 3 + 2) * 4 + 0xb0));
    while (*cnt & 0x80000000) {
    }
    flags                                            = OS_DisableInterrupts();
    *(volatile u32 *) (0x4000000 + dmaNo * 4 + 0xe0) = data;
    MIi_DmaSetParams_wait_noInt(dmaNo, (void *) (0x4000000 + dmaNo * 4 + 0xe0), dest, (size >> 2) | 0x85000000);
    OS_RestoreInterrupts(flags);
    while (*cnt & 0x80000000) {
    }
}
