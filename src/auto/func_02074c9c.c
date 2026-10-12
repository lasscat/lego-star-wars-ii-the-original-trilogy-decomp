#include "m2c.h"

M2C_UNK func_020755d8(void *);                      /* extern */

void *func_02074c9c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    func_020755d8(arg0 + 0x10);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    return arg0;
}
