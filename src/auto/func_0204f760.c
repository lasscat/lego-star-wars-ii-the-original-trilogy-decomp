#include "m2c.h"

void func_0204f760(s32 a0, s32 a1) {
    s32 v = *(s32 *) &a1;

    *(s32 *) (a0 + 0x30) = v;
    *(s32 *) (a0 + 0x14) = v;
    *(s32 *) (a0 + 0x18) = v;
    *(s32 *) (a0 + 0x1c) = v;
    *(s32 *) (a0 + 0x20) = v;
}
