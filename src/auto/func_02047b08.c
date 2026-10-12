#include "m2c.h"

M2C_UNK func_0204a1c4(s32);                         /* extern */
M2C_UNK func_0204a400(s32, s32, s32);               /* extern */

void func_02047b08(void *arg0) {
    s32 temp_r1;

    func_0204a1c4(M2C_FIELD(arg0, s32 *, 4) + 0x5CE);
    temp_r1 = M2C_FIELD(arg0, s32 *, 4);
    func_0204a400(temp_r1 + 0x5CE, temp_r1, M2C_FIELD(arg0, s32 *, 0x10));
}
