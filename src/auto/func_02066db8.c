#include "m2c.h"

M2C_UNK func_0205e860(s32);                         /* extern */

void *func_02066db8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        func_0205e860(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_FIELD(arg0, s32 *, 8) = 0;
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    return arg0;
}
