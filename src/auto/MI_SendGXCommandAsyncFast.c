#include "m2c.h"

M2C_UNK MIi_DmaSetParams(s32, M2C_UNK, s32, s32);      /* extern */
M2C_UNK OSi_EnterDmaCallback(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK MI_WaitDma(s32);                         /* extern */
M2C_UNK MIi_CheckAnotherAutoDMA(s32, M2C_UNK);                /* extern */
M2C_UNK MIi_CheckDma0SourceAddress(s32, M2C_UNK, u32, M2C_UNK);  /* extern */
extern M2C_UNK MIi_GXDmaParams;
extern M2C_UNK MIi_DMAFastCallback;

void MI_SendGXCommandAsyncFast(s32 arg0, M2C_UNK arg1, u32 arg2, M2C_UNK (*arg3)(s32), s32 arg4) {
    if (arg2 == 0) {
        if (arg3 == NULL) {
            return;
        }
        arg3(arg4);
        return;
    }
    do {

    } while (M2C_FIELD(&MIi_GXDmaParams, volatile s32 *, 0) != 0);
    M2C_FIELD(&MIi_GXDmaParams, volatile s32 *, 0)      = 1;
    M2C_FIELD(&MIi_GXDmaParams, volatile s32 *, 4)      = arg0;
    M2C_FIELD(&MIi_GXDmaParams, M2C_UNK(**)(s32), 0x10) = arg3;
    M2C_FIELD(&MIi_GXDmaParams, volatile s32 *, 0x14)   = arg4;
    MIi_CheckAnotherAutoDMA(arg0, 0x38000000);
    MIi_CheckDma0SourceAddress(arg0, arg1, arg2, 0);
    MI_WaitDma(arg0);
    OSi_EnterDmaCallback(arg0, &MIi_DMAFastCallback, 0);
    MIi_DmaSetParams(arg0, arg1, 0x04000400, -0x03C00000 | (arg2 >> 2));
}
