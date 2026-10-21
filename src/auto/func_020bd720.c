#include "m2c.h"

/* func_020bd720 - adds a scaled value to a 12.4 fixed point accumulator.
 *
 * The object (a0) holds the scale at +0x10 and the accumulator at +0x64.
 * The second argument is the value to add; the game passes it in r1 but the
 * original code reads it back from the argument home area (the
 * "push {r0, r1, r2, r3}" prologue of a variadic function), so the value is
 * read through the address of the parameter.  Reading it as a volatile
 * keeps it in that home slot and reproduces the game's register allocation
 * (the accumulator in r1, the value in r2, the scale in r3, the 64 bit
 * product low word in ip).
 *
 * The accumulator is loaded after the delta has been computed so that its
 * live range stays short; that is what puts it in r1 and lets the final
 * "asr r1, r1, #0xc" shift the old accumulator in place.
 */
s32 func_020bd720(s32 a0, s32 a1) {
    s32 scale                  = M2C_FIELD(a0, s32 *, 0x10);
    s32 delta                  = (s32) (((s64) scale * *(volatile s32 *) &a1 + 0x800) >> 12);
    s32 acc                    = M2C_FIELD(a0, s32 *, 0x64);
    s32 nacc                   = acc + delta;
    M2C_FIELD(a0, s32 *, 0x64) = nacc;
    return (nacc >> 12) - (acc >> 12);
}
