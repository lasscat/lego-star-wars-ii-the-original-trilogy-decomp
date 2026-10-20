#include "m2c.h"
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern u32 OS_TryLockCartridge(s32);
extern u32 func_020ccec0(u32);
extern void WaitByLoop(s32);

void CTRDGi_LockByProcessor(s32 a0, s32 *a1) {
    u32 flag;
    for (;;) {
        *(u32 *) ((s8 *) a1 + 4) = OS_DisableInterrupts();
        flag = func_020ccec0(0x27fffe8) & 0x40;
        *(u32 *) ((s8 *) a1 + 0) = flag;
        if (flag != 0) {
            return;
        }
        if (OS_TryLockCartridge(a0) == 0) {
            return;
        }
        OS_RestoreInterrupts(*(u32 *) ((s8 *) a1 + 4));
        WaitByLoop(1);
    }
}
