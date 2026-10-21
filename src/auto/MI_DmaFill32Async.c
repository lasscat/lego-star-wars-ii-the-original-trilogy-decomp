#include "m2c.h"

typedef void (*MIDmaCallback)(void *);

extern void MI_WaitDma(u32 dmaNo);                                   /* extern */
extern void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback cb, void *arg); /* extern */
extern void MIi_DmaSetParams_noInt(u32 dmaNo, void *src, void *dst, u32 ctrl); /* extern */
extern u32 OS_DisableInterrupts(void);                              /* extern */
extern u32 OS_RestoreInterrupts(u32 state);                         /* extern */

void MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg) {
    if (size == 0) {
        if (callback == NULL) {
            return;
        }
        callback(arg);
        return;
    }
    MI_WaitDma(dmaNo);
    if (callback != NULL) {
        u32 ime;
        OSi_EnterDmaCallback(dmaNo, callback, arg);
        ime                                        = OS_DisableInterrupts();
        *(volatile u32 *) (0x040000e0 + dmaNo * 4) = data;
        MIi_DmaSetParams_noInt(dmaNo, (void *) (0x040000e0 + dmaNo * 4), dest, (size >> 2) | 0xC5000000);
        OS_RestoreInterrupts(ime);
    } else {
        u32 ime;
        ime                                        = OS_DisableInterrupts();
        *(volatile u32 *) (0x040000e0 + dmaNo * 4) = data;
        MIi_DmaSetParams_noInt(dmaNo, (void *) (0x040000e0 + dmaNo * 4), dest, (size >> 2) | 0x85000000);
        OS_RestoreInterrupts(ime);
    }
}
