#include "m2c.h"

M2C_UNK OS_CreateThread(void *, M2C_UNK *, void *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK OS_WakeupThreadDirect(void *);                      /* extern */
s32 OS_DisableInterrupts();                                /* extern */
M2C_UNK OS_RestoreInterrupts(s32);                         /* extern */
M2C_UNK CTRDGi_InitTaskInfo(M2C_UNK *);                   /* extern */
extern void *ctrdgi_task_work;
extern M2C_UNK ctrdgi_task_list;
extern M2C_UNK __console_exit;
extern M2C_UNK CTRDGi_TaskThread;

void CTRDGi_InitTaskThread(void *arg0) {
    s32 temp_r4;

    temp_r4 = OS_DisableInterrupts();
    if (ctrdgi_task_work == NULL) {
        ctrdgi_task_work = arg0;
        CTRDGi_InitTaskInfo(arg0 + 0xC4);
        CTRDGi_InitTaskInfo(&ctrdgi_task_list);
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        OS_CreateThread(arg0, &CTRDGi_TaskThread, arg0, &__console_exit, 0x400, 0x14);
        OS_WakeupThreadDirect(arg0);
    }
    OS_RestoreInterrupts(temp_r4);
}
