#include "m2c.h"

void func_020a1434(s32 a0, s32 a1, s32 a2) {
    *(s32 *) (a0 + 0x2CC) = *(s32 *) &a1;
    *(s32 *) (a0 + 0x2D0) = *(s32 *) &a2;
}
