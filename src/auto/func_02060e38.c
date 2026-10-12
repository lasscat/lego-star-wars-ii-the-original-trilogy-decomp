#include "m2c.h"

M2C_UNK func_02060d3c();                            /* extern */

void func_02060e38(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x48) == 0) {
        return;
    }
    func_02060d3c(arg0);
}
