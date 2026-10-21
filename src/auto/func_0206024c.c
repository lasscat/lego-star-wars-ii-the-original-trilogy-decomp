#include "m2c.h"

/* func_0206024c (0x0206024c, 68 bytes)
 *
 * The function is variadic: the "push {r0, r1, r2, r3}" prologue is MWCC's
 * argument home area, which only variadic functions get.  The second and the
 * third argument are read back from that home area ("ldr ip, [sp, #4]" and
 * "ldr r3, [sp, #8]"), so the original code takes the address of the
 * parameters.
 *
 * Semantics: the object keeps the previous position (f08/f0c) and an
 * accumulated position (f10/f14); the function adds the delta to the
 * accumulated position and then stores the new previous position.
 *
 * The volatile qualifiers are what makes MWCC keep the exact register and
 * instruction schedule of the original:
 *  - the parameters are read through a volatile pointer, so the reloads stay
 *    at the top of the function instead of being sunk to their use;
 *  - the fields are read through a volatile pointer, so the loaded values
 *    are not copy propagated into the addition and the accumulator keeps the
 *    lower register (r1) while the difference gets r2;
 *  - the reload of the third parameter is done after the first half of the
 *    function, which is where the original reads it.
 */

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
} Unk_0206024c;

void func_0206024c(volatile Unk_0206024c *p, s32 x, s32 y, ...) {
    s32 vx = *(volatile s32 *) &x;
    s32 vy;

    {
        s32 d  = vx - p->f08;
        s32 a  = p->f10;
        s32 r  = a + d;
        p->f10 = r;
    }
    vy = *(volatile s32 *) &y;
    {
        s32 e  = vy - p->f0c;
        s32 b  = p->f14;
        s32 r2 = b + e;
        p->f14 = r2;
    }
    p->f08 = vx;
    p->f0c = vy;
}
