/* Reconstructed from USA ARM9 at 0x0203fe38 (148 bytes).
 *
 * obj is a 7 word record: [0..3] are cleared, [4] is set to 0x2000 and
 * [5], [6] are cleared.  p is a controller-ish object (its vtable is
 * called through p[0x20] by func_02017e8c) and q is passed through to
 * the ITCM helper func_01ffa338.
 */
#include "m2c.h"

extern u32 data_0210930c[];

void func_02017e8c(s32 *, s32 *);
void func_01ffa338(s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);

void func_0203fe38(s32 *obj, s32 *p, s32 *q) {
    s32 buf[6];

    obj[0] = 0;
    obj[1] = 0;
    obj[2] = 0;
    obj[3] = 0;
    obj[4] = 0x2000;
    obj[5] = 0;
    obj[6] = 0;

    if (p == 0) {
        return;
    }

    /* the six word output buffer is cleared with a fill loop */
    {
        s32 *q2 = buf;
        s32 v   = 0;
        do {
            *q2++ = v;
        } while (q2 < buf + 6);
    }

    func_02017e8c(p, buf);
    func_01ffa338(p, p[8], buf, q, (s32 *) ((u32 *) data_0210930c[0x1a])[0xe1], obj);
}
