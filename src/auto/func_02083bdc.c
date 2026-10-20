#include "m2c.h"

s32 func_02083bdc(s32 *a0, s32 a1, s32 a2) {
    u8 **table;
    u8 *p;
    u8 b;
    if (a2 == 0) {
        return 0;
    }
    table = M2C_FIELD(a0, u8 ***, 0x54);
    p     = table[a1] + a2;
    b     = *(p - 1);
    if (b != 0xff) {
        return a0[b];
    }
    return 0;
}
