#include "m2c.h"

s32 IsVramTransferTaskQueueFull_(M2C_UNK *);                       /* extern */
M2C_UNK NNSi_GfdPushVramTransferTaskQueue(M2C_UNK *);                   /* extern */
void *NNSi_GfdGetEndVramTransferTaskQueue(M2C_UNK *);                     /* extern */
extern M2C_UNK s_VramTransferManager;

s32 NNS_GfdRegisterNewVramTransferTask(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_r0;
    M2C_UNK *local;

    local = &s_VramTransferManager;
    if (IsVramTransferTaskQueueFull_(local) != 0) {
        return 0;
    }
    temp_r0                        = NNSi_GfdGetEndVramTransferTaskQueue(local);
    M2C_FIELD(temp_r0, s32 *, 0)   = arg0;
    M2C_FIELD(temp_r0, s32 *, 4)   = arg2;
    M2C_FIELD(temp_r0, s32 *, 8)   = arg1;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg3;
    NNSi_GfdPushVramTransferTaskQueue(local);
    M2C_FIELD(local, s32 *, 0x10) = (s32) (M2C_FIELD(local, s32 *, 0x10) + M2C_FIELD(temp_r0, s32 *, 0xC));
    return 1;
}
