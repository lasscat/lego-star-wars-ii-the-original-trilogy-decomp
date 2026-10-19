#include "m2c.h"

void *func_02067b0c(s32, M2C_UNK);

void func_020906a8(void *arg0, void *arg1, s32 arg2, M2C_UNK arg3) {
    void *t;
    s32 *o;
    s16 *s;
    s32 a, b, c;

    o    = arg0;
    t    = func_02067b0c(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, void **, 0x38C), void **, 4), s32 *, 0x34) + (arg2 * 8), arg3);
    s    = t;
    c    = (s32) s[2] << 0xC;
    b    = (s32) s[1] << 0xC;
    a    = (s32) s[0] << 0xC;
    o[0] = a;
    o[1] = b;
    o[2] = c;
}
