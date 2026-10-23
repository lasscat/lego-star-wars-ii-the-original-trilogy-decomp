/* Reconstructed from USA ARM9 at 0x020be800 (140 bytes).
 *
 * Fixed point interpolation of a request value.  The object fields are
 * read through volatile pointers: the original issues the loads of the
 * else branch in the order 0x74, 0x08, 0x0c and the compiler must not
 * sink or reorder them.  The two 64 bit products are truncated to 32
 * bits before the second shift, which is what the original does.
 */
#include "m2c.h"

extern M2C_UNK data_0210e2f8;
s32 FX_Div(s32, s32);                                 /* extern */

void func_020be800(void *arg0, void *arg1) {
    s32 var_r1;
    volatile s32 *f = (volatile s32 *) arg0;
    volatile s32 *g = (volatile s32 *) arg1;

    if (f[4] != 0) {
        var_r1 = (f[3] - f[2]) >> 12;
    } else {
        s32 t  = g[29];
        s32 pa = (s32) (((s64) f[2] * t + 0x800) >> 12);
        s32 pc = (s32) (((s64) f[3] * t + 0x800) >> 12);
        var_r1 = (pc >> 12) - (pa >> 12);
    }
    ((s32 *) &data_0210e2f8)[M2C_FIELD(arg1, s32 *, 0x4C)] =
        FX_Div(M2C_FIELD(arg0, s32 *, 0x14) - M2C_FIELD(arg1, s32 *, 0x30), var_r1 << 12);
}
