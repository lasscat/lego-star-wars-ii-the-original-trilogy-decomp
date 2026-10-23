/* Reconstructed from USA ARM9 at 0x020cc828 (116 bytes).
 *
 * SDK interrupt wait helper: optionally clears the pending IRQ flags of the
 * requested mask, then blocks on the SDK IRQ thread queue until one of those
 * interrupts becomes pending again.
 *
 * The SDK keeps its interrupt flag word at the end of the DTCM autoload area
 * (SDK_AUTOLOAD_DTCM_START + 0x3ff8).  SDK_AUTOLOAD_DTCM_START and
 * OSi_IrqThreadQueue are symbols of the DTCM module, but the ARM9 module can
 * still reference them by name: the DTCM objects are part of the same link and
 * define them at 0x027e0000 and 0x027e0e7c.
 */
#include "m2c.h"

extern char SDK_AUTOLOAD_DTCM_START[];
extern u8 OSi_IrqThreadQueue[];

extern s32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(s32 state);
extern void OS_SleepThread(void *queue);

void OS_WaitIrq(s32 clear, u32 mask) {
    s32 state;
    u32 *flags;
    u8 *base;

    state = OS_DisableInterrupts();
    if (clear != 0) {
        base = SDK_AUTOLOAD_DTCM_START;
        *(u32 *) (base + 0x3ff8) &= ~mask;
    }
    OS_RestoreInterrupts(state);
    base = SDK_AUTOLOAD_DTCM_START;
    if ((mask & *(u32 *) (base + 0x3ff8)) == 0) {
        flags = (u32 *) (base + 0x3ff8);
        do {
            OS_SleepThread(OSi_IrqThreadQueue);
        } while ((mask & *flags) == 0);
    }
}
