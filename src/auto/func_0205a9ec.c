#include "m2c.h"

M2C_UNK func_0205aa40(void *);                      /* extern */
extern s32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32, M2C_UNK, M2C_UNK);

void func_0205a9ec(void *arg0) {
    s32 temp_r0;

    if (M2C_FIELD(arg0, u8 *, 0) != 0) {
        return;
    }
    temp_r0                   = NNS_GfdDefaultFuncAllocPlttVram(M2C_FIELD(arg0, u16 *, 2) * 2, 0, 0);
    M2C_FIELD(arg0, s32 *, 8) = temp_r0;
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0) = 1U;
    func_0205aa40(arg0);
}
