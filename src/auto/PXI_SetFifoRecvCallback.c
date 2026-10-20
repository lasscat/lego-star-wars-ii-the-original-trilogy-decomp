/* Reconstructed from USA ARM9 at 0x020d1240 (76 bytes).
 * Registers (or clears) the receive callback of a PXI FIFO channel.
 */
#include "m2c.h"

extern void *FifoRecvCallbackTable[]; /* extern */

u32 OS_DisableInterrupts(void);       /* extern */
void OS_RestoreInterrupts(u32 state);  /* extern */

void PXI_SetFifoRecvCallback(u32 index, void (*callback)(void)) {
    u32 *words = (u32 *)0x027FFC00;
    u32 state;

    state = OS_DisableInterrupts();
    FifoRecvCallbackTable[index] = callback;
    if (callback != NULL) {
        words[0x388 / 4] |= (1 << index);
    } else {
        words[0x388 / 4] &= ~(1 << index);
    }
    OS_RestoreInterrupts(state);
}
