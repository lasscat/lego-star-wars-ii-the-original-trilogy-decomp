#include "m2c.h"

M2C_UNK func_02029664(s32, void *);                 /* extern */
s32 func_0202cb68(s32);                             /* extern */
s32 func_0202cb7c(s32);                             /* extern */

void func_02044dd4(void *arg0) {
    func_02029664(M2C_FIELD(arg0, s32 *, 4) + 0x608, arg0 + 0x18);
    if (M2C_FIELD(arg0, u8 *, 0x24) == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = func_0202cb68(M2C_FIELD(arg0, s32 *, 4) + 0x5E0);
    M2C_FIELD(arg0, s32 *, 0x14) = func_0202cb7c(M2C_FIELD(arg0, s32 *, 4) + 0x5E0);
}
