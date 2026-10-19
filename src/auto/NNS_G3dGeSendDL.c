#include "m2c.h"

M2C_UNK NNS_G3dGeFlushBuffer();                            /* extern */
M2C_UNK NNS_G3dGeBufferOP_N(s32, s32 *, s32);             /* extern */
M2C_UNK MI_SendGXCommandAsyncFast(s32, s32 *, u32, M2C_UNK *, s32 *); /* extern */
extern s32 GXi_DmaId;
extern s32 data_027e0e78;
extern M2C_UNK func_01ffc450;

void NNS_G3dGeSendDL(s32 *arg0, u32 arg1) {
    if ((arg1 < 0x100U) || (GXi_DmaId == -1)) {
        NNS_G3dGeBufferOP_N(*arg0, ((s8 *) arg0 + 4), (arg1 >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    data_027e0e78 = 1;
    MI_SendGXCommandAsyncFast(GXi_DmaId, arg0, arg1, &func_01ffc450, &data_027e0e78);
}
