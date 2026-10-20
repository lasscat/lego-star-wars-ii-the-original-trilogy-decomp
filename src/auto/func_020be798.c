/* Reconstructed from USA ARM9 at 0x020be798 (80 bytes).
 *
 * func_020be798 is a vtable method of the same class as func_020be768
 * (0x020be768): it adds a scaled table entry to the accumulator stored at
 * +0x6c of the object.
 *
 *     obj->f6c += ((table[obj->f4c] * factor + 0x800) >> 12)
 *
 * table is data_0210e1f8, the factor is the third argument (r2).
 *
 * The original reads the factor back through the address of the parameter,
 * so the value is taken from the argument home slot at [sp, #0x10] instead of
 * from the register; the prologue therefore saves r0-r3.  Reading it through
 * a volatile pointer keeps the parameter in that slot and reproduces the
 * original register allocation (index in r3, factor in r2, table entry
 * reusing r3, accumulator in r0).
 *
 * The two volatile stores are the original's stores of the result into its
 * (otherwise unused) locals.
 */
#include "m2c.h"

extern M2C_UNK data_0210e1f8;

void func_020be798(s32 arg0, void *arg1, s32 arg2) {
    volatile s32 sp0;
    volatile s32 sp4;
    s32 temp_r0;
    s32 val                      = ((s32 *) &data_0210e1f8)[M2C_FIELD(arg1, s32 *, 0x4C)];
    s32 delta                    = (s32) (((s64) val * *(volatile s32 *) &arg2 + 0x800) >> 12);
    s32 acc                      = M2C_FIELD(arg1, s32 *, 0x6C);
    temp_r0                      = acc + delta;
    sp0                          = temp_r0;
    sp4                          = temp_r0;
    M2C_FIELD(arg1, s32 *, 0x6C) = temp_r0;
}
