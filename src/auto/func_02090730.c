#include "m2c.h"

s32 func_02090730(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 *p                   = (u8 *) arg0 + 0x3e8;
    *(s32 *) (p + arg1 * 8) = arg2;
    p += arg1 * 8;
    p[5] = (u8) arg3;
    p[6] = (u8) arg4;
    p[7] = (u8) arg5;
    p[4] = 1;
    return 1;
}
