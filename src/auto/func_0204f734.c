#include "m2c.h"

extern void func_0204f760(s32 a0, s32 a1, ...);

/* Q12 fixed point: the scale is (a2->f10 * a3->f30 + 0x800) >> 12, and the
 * raw 64-bit product is passed on as its high and low halves. */
void func_0204f734(s32 a0, s32 a1, s32 a2, s32 a3) {
    s64 p = (s64) M2C_FIELD((s32 *) a2, s32 *, 0x10) * M2C_FIELD((s32 *) a3, s32 *, 0x30);
    s64 q = p + 0x800;

    func_0204f760(a0, (s32) (q >> 12), (s32) (q >> 32), (s32) q, (s32) (q >> 12));
}
