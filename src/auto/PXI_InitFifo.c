/* Reconstructed from USA ARM9 at 0x020d1140 (0x100 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern void OS_ResetRequestIrqMask(u32 mask);
extern void OS_SetIrqFunction(u32 mask, void (*handler)(void));
extern void OS_EnableIrqMask(u32 mask);
extern void PXIi_HandlerRecvFifoNotEmpty(void);

extern volatile u16 FifoCtrlInit;
extern void (*FifoRecvCallbackTable[0x20])(void);

void PXI_InitFifo(void) {
    u32 state;
    u32 *pxi;
    volatile u16 *sync;
    s32 i;
    s32 timeout;
    u16 v;
    u32 n;

    state = OS_DisableInterrupts();
    if (FifoCtrlInit == 0) {
        FifoCtrlInit   = 1;
        pxi            = (u32 *) 0x027FFC00;
        pxi[0x388 / 4] = 0;
        for (i = 0; i < 0x20; i++) {
            FifoRecvCallbackTable[i] = NULL;
        }
        sync  = (volatile u16 *) 0x04000184;
        *sync = 0xc408;
        OS_ResetRequestIrqMask(0x40000);
        OS_SetIrqFunction(0x40000, PXIi_HandlerRecvFifoNotEmpty);
        OS_EnableIrqMask(0x40000);
        sync    = (volatile u16 *) 0x04000180;
        i       = 0;
        timeout = 0x3e8;
        for (;;) {
            v     = *sync;
            n     = v & 0xf;
            *sync = n << 8;
            if (n == 0 && i > 4) {
                break;
            }
            timeout = 0x3e8;
            if ((*sync & 0xf) == n) {
                for (;;) {
                    if (timeout <= 0) {
                        i = 0;
                        break;
                    }
                    v = *sync;
                    timeout--;
                    if ((v & 0xf) == n) {
                        continue;
                    }
                    break;
                }
            }
            i++;
        }
    }
    OS_RestoreInterrupts(state);
}
