#include "m2c.h"

extern s32 FX_Div(s32, s32);

/* func_020bf7e8(obj, a) computes a 16-bit value and stores it at obj+0x24.
 *
 * The quotient comes from the fixed point helper FX_Div(0x1000, a << 12),
 * i.e. the 20.12 result 4096 / a.  That value is then scaled by 0x10000000
 * with the usual fixed point rounding term and shifted back down by 12,
 * the same (x * y + 0x800) >> 12 idiom that func_020be798 uses.
 *
 * The original keeps the scaled value in a 16-bit stack slot (sp+2) and reads
 * it back from there before copying it into a second slot (sp+0) and into the
 * object member, so both slots are volatile here to reproduce that traffic.
 */
void func_020bf7e8(void *obj, s32 a) {
    volatile u16 tmp[2];
    s32 v;
    u16 w;

    v                           = FX_Div(0x1000, a << 12);
    tmp[1]                      = (u16) (s32) (((s64) v * 0x10000000 + 0x800) >> 12);
    w                           = tmp[1];
    tmp[0]                      = w;
    M2C_FIELD(obj, u16 *, 0x24) = w;
}
