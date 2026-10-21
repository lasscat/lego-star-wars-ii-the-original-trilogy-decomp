#include "m2c.h"

typedef s32 (*fn_t)(s32 *, s32, s32);

void func_0205a6d0(s32 *p, s32 a1, s32 a2, s32 a3) {
    s32 n;
    s32 *q;
    fn_t fn;
    s32 ret;
    s32 shift;

    n = *(s32 *) ((s8 *) p + 0x28);
    q = (s32 *) ((s8 *) p + (n >> 1));
    if (n & 1) {
        fn = *(fn_t *) ((u8 *) (*(s32 *) q) + *(s32 *) ((s8 *) p + 0x24));
    } else {
        fn = *(fn_t *) ((s8 *) p + 0x24);
    }
    ret = fn(q, a1, a2);

    shift = (a1 & 3) << 1;
    *(u8 *) (*(s32 *) p + ret) &= ~(3 << shift);
    *(u8 *) (*(s32 *) p + ret) |= ((a3 & 3) << shift);
}
