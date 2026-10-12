#include "m2c.h"

void *func_020531d8(M2C_UNK);                       /* extern */

void func_02053adc(u16 *arg0, M2C_UNK arg1) {
    *arg0 = M2C_FIELD(func_020531d8(arg1), u16 *, 0x1C);
}
