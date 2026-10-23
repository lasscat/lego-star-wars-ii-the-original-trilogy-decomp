/* Reconstructed from USA ARM9 at 0x020d1338 (280 bytes).
 * PXI receive-FIFO interrupt handler.
 *
 * The ARM7 hands a 32 bit word to the ARM9 through the shared word at
 * 0x04100000.  Its layout is
 *   bits  0- 4 : FIFO index
 *   bit      5 : response/acknowledge flag
 *   bits  6-31 : payload
 * The word is dispatched to FifoRecvCallbackTable[index]; when no callback
 * is registered and the acknowledge flag is clear, the word is echoed back
 * with the flag set through the IPC send register at 0x4000188.
 */
#include "m2c.h"

extern void *FifoRecvCallbackTable[];

u32 OS_DisableInterrupts(void);       /* extern */
void OS_RestoreInterrupts(u32 state);  /* extern */

typedef union {
    u32 raw;
    struct {
        u32 idx : 5;
        u32 flag : 1;
        u32 data : 26;
    } b;
} PxiMsg;

void PXIi_HandlerRecvFifoNotEmpty(void) {
    PxiMsg m;
    s32 mode;
    u32 st;
    volatile u16 *cnt = (volatile u16 *) 0x4000184;

    for (;;) {
        if (*cnt & 0x4000) {
            *cnt |= 0xc000;
            mode = -3;
        } else {
            st = OS_DisableInterrupts();
            if (*cnt & 0x100) {
                OS_RestoreInterrupts(st);
                mode = -4;
            } else {
                m.raw = *(u32 *) 0x04100000;
                OS_RestoreInterrupts(st);
                mode = 0;
            }
        }
        if (mode == -4) {
            return;
        }
        if (mode == -3) {
            continue;
        }
        if (m.b.idx == 0) {
            continue;
        }
        {
            void (*cb)(u32, u32, u32) = (void (*)(u32, u32, u32)) FifoRecvCallbackTable[m.b.idx];
            if (cb != NULL) {
                cb(m.b.idx, m.b.data, m.b.flag);
                continue;
            }
        }
        if (m.b.flag != 0) {
            continue;
        }
        m.b.flag = 1;
        if (*cnt & 0x4000) {
            *cnt |= 0xc000;
            continue;
        }
        st = OS_DisableInterrupts();
        if (*cnt & 0x2) {
            OS_RestoreInterrupts(st);
            continue;
        }
        *(volatile u32 *) 0x4000188 = m.raw;
        OS_RestoreInterrupts(st);
    }
}
