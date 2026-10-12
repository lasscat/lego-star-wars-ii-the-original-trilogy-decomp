#include "m2c.h"

void *func_020531d8(M2C_UNK);                       /* extern */

void func_02053af8(s32 *arg0, M2C_UNK arg1) {
    *arg0 = M2C_FIELD(func_020531d8(arg1), s32 *, 0x18);
}
