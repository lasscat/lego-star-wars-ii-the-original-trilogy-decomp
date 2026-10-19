#include "m2c.h"

u16 GetNextIndex_(void *, u16);                     /* extern */
s32 IsVramTransferTaskQueueFull_();                                /* extern */

s32 NNSi_GfdPushVramTransferTaskQueue(void *arg0) {
    if (IsVramTransferTaskQueueFull_() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, u16 *, 0xA) = GetNextIndex_(arg0, M2C_FIELD(arg0, u16 *, 0xA));
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) + 1);
    return 1;
}
