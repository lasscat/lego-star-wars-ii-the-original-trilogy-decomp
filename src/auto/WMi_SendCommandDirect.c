#include "m2c.h"

M2C_UNK OS_SendMessage(M2C_UNK *, s32, M2C_UNK);     /* extern */
M2C_UNK DC_StoreRange(s32, M2C_UNK);                /* extern */
M2C_UNK MI_CpuCopy8(M2C_UNK, s32, M2C_UNK);       /* extern */
s32 PXI_SendWordByFifo(M2C_UNK, s32, M2C_UNK);           /* extern */
s32 WmGetCommandBuffer4Arm7();                                /* extern */
extern M2C_UNK bufMsgQ;

s32 WMi_SendCommandDirect(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = WmGetCommandBuffer4Arm7();
    if (temp_r0 == 0) {
        return 8;
    }
    MI_CpuCopy8(arg0, temp_r0, arg1);
    DC_StoreRange(temp_r0, arg1);
    temp_r4 = PXI_SendWordByFifo(0xA, temp_r0, 0);
    OS_SendMessage(&bufMsgQ, temp_r0, 1);
    if (temp_r4 < 0) {
        return 8;
    }
    return 2;
}
