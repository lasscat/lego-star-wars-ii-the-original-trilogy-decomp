#include "m2c.h"

M2C_UNK func_02060e6c();                            /* extern */

void func_02060e50(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 8) & 0x80000) != 0x80000) {
        return;
    }
    func_02060e6c(arg0);
}
