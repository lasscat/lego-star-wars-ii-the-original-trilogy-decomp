#include "m2c.h"

M2C_UNK NNS_GfdRegisterNewVramTransferTask(M2C_UNK, u32, s32, s32);      /* extern */

void func_0205aa40(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        return;
    }
    NNS_GfdRegisterNewVramTransferTask(1, (u32) (M2C_FIELD(arg0, s32 *, 8) << 0x10) >> 0xD, M2C_FIELD(arg0, s32 *, 4),
                                       M2C_FIELD(arg0, u16 *, 2) * 2);
}
