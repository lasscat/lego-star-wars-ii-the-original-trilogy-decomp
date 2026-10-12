#include "m2c.h"

M2C_UNK func_0202cbd4();                            /* extern */

void func_0202db74(s32 *arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0x5FC) == 0) {
        *arg0 = 0xA000;
        return;
    }
    func_0202cbd4();
}
