#include "m2c.h"

M2C_UNK func_0205d6f8(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b9c4c(void *);                      /* extern */

void *func_020b9a60(void *arg0) {
    func_0205d6f8(arg0, 0xA);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    func_020b9c4c(arg0);
    return arg0;
}
