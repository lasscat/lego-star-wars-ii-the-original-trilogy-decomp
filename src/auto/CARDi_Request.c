#include "m2c.h"

M2C_UNK OS_SleepThread(M2C_UNK);                     /* extern */
M2C_UNK DC_InvalidateRange(s32 *, M2C_UNK);              /* extern */
M2C_UNK DC_FlushRange(s32 *, M2C_UNK);              /* extern */
M2C_UNK DC_WaitWriteBufferEmpty();                            /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
M2C_UNK OS_SpinWait(M2C_UNK);                     /* extern */
s32 PXI_IsCallbackReady(M2C_UNK, M2C_UNK);                /* extern */
s32 PXI_SendWordByFifo(M2C_UNK, s32 *, M2C_UNK);         /* extern */

s32 CARDi_Request(void *arg0, s32 *arg1, s32 arg2) {
    s32 sp0;
    s32 *temp_r8;
    s32 temp_r0;
    s32 temp_r1;
    s32 temp_r8_2;

    sp0 = arg2;
    if (!(M2C_FIELD(arg0, volatile s32 *, 0x114) & 2)) {
        M2C_FIELD(arg0, volatile s32 *, 0x114) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x114) | 2);
        if (PXI_IsCallbackReady(0xB, 1) == 0) {
            do {
                OS_SpinWait(0x64);
            } while (PXI_IsCallbackReady(0xB, 1) == 0);
        }
        CARDi_Request(arg0, NULL, 1);
    }
    DC_FlushRange(M2C_FIELD(arg0, s32 **, 0), 0x60);
    DC_WaitWriteBufferEmpty();
loop_6:
    M2C_FIELD(arg0, s32 **, 4)             = arg1;
    M2C_FIELD(arg0, volatile s32 *, 0x114) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x114) | 0x20);
    do {

    } while (PXI_SendWordByFifo(0xB, arg1, 1) < 0);
    if (arg1 == NULL) {
        temp_r8 = M2C_FIELD(arg0, s32 **, 0);
        do {

        } while (PXI_SendWordByFifo(0xB, temp_r8, 1) < 0);
    }
    temp_r8_2 = OS_DisableInterrupts();
    if (M2C_FIELD(arg0, volatile s32 *, 0x114) & 0x20) {
        do {
            OS_SleepThread(0);
        } while (M2C_FIELD(arg0, volatile s32 *, 0x114) & 0x20);
    }
    OS_RestoreInterrupts(temp_r8_2);
    DC_InvalidateRange(M2C_FIELD(arg0, s32 **, 0), 0x60);
    temp_r1 = *M2C_FIELD(arg0, s32 **, 0);
    if (temp_r1 == 4) {
        temp_r0 = sp0 - 1;
        sp0     = temp_r0;
        if (temp_r0 > 0) {
            goto loop_6;
        }
    }
    if (temp_r1 == 0) {
        return 1;
    }
    return 0;
}
