/* Reconstructed from USA ARM9 at 0x020be6dc (140 bytes).
 *
 * The object fields are read through volatile pointers: the original issues
 * the three loads of the else branch in the order 0x74, 0x08, 0x0c and the
 * compiler must not sink or reorder them.  The two 64-bit products are
 * truncated to 32 bits before the second shift, which is what the original
 * does (the high half of the shifted product is dropped).
 */
#include "m2c.h"

extern M2C_UNK data_0210e1f8;
s32 FX_Div(s32, s32);                                 /* extern */

void func_020be6dc(void *arg0, void *arg1) {
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
    ((s32 *) &data_0210e1f8)[M2C_FIELD(arg1, s32 *, 0x4C)] =
        FX_Div(M2C_FIELD(arg0, s32 *, 0x14) - M2C_FIELD(arg1, s32 *, 0x6C), var_r1 << 12);
}
