#include "m2c.h"
typedef s32 (*fn_t)(s32 *, s32, s32);
void func_0205a740(s32 *p, s32 a1, s32 a2, u8 val) {
    s32 n;
    s32 *q;
    fn_t fn;
    s32 ret;
    n = *(s32 *) ((s8 *) p + 0x28);
    q = (s32 *) ((s8 *) p + (n >> 1));
    if (n & 1) {
        fn = *(fn_t *) ((u8 *) (*(s32 *) q) + *(s32 *) ((s8 *) p + 0x24));
    } else {
        fn = *(fn_t *) ((s8 *) p + 0x24);
    }
    ret = fn(q, a1, a2);
    *(u8 *) (*(s32 *) p + ret) = val;
}
