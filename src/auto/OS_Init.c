#include "m2c.h"

M2C_UNK OS_InitIrqTable();                            /* extern */
M2C_UNK OS_SetIrqStackChecker();                            /* extern */
M2C_UNK OS_InitLock();                            /* extern */
M2C_UNK OS_InitThread();                            /* extern */
M2C_UNK OS_InitArena();                            /* extern */
M2C_UNK OS_InitArenaEx();                            /* extern */
M2C_UNK OS_InitException();                            /* extern */
M2C_UNK OS_InitVAlarm();                            /* extern */
M2C_UNK OS_InitReset();                            /* extern */
M2C_UNK OSi_InitVramExclusive();                            /* extern */
M2C_UNK MI_Init();                            /* extern */
M2C_UNK PXI_Init();                            /* extern */
M2C_UNK PM_Init();                            /* extern */
M2C_UNK CARD_Init();                            /* extern */
M2C_UNK CTRDG_Init();                            /* extern */

void OS_Init(void) {
    OS_InitArena();
    PXI_Init();
    OS_InitLock();
    OS_InitArenaEx();
    OS_InitIrqTable();
    OS_SetIrqStackChecker();
    OS_InitException();
    MI_Init();
    OS_InitVAlarm();
    OSi_InitVramExclusive();
    OS_InitThread();
    OS_InitReset();
    CTRDG_Init();
    CARD_Init();
    PM_Init();
}
