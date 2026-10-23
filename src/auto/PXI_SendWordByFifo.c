#include "m2c.h"

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);

typedef union {
    u32 word;
    struct {
        u32 channel : 5;
        u32 flag : 1;
        u32 rest : 26;
    } bits;
} PxiHeader;

s32 PXI_SendWordByFifo(s32 channel, s32 data, s32 flags) {
    PxiHeader h;

    h.bits.channel = channel;
    h.bits.flag    = flags;
    h.word         = (data << 6) | (h.word & 0x3F);

    if (*(volatile u16 *) 0x04000184 & 0x4000) {
        *(volatile u16 *) 0x04000184 |= 0xC000;
        return -1;
    }
    {
        u32 state = OS_DisableInterrupts();
        if (*(volatile u16 *) 0x04000184 & 0x2) {
            OS_RestoreInterrupts(state);
            return -2;
        }
        *(volatile u32 *) 0x04000188 = h.word;
        OS_RestoreInterrupts(state);
    }
    return 0;
}
