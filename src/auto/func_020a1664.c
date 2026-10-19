/* Reconstructed from USA ARM9 at 0x020a1664 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

u16 func_020985d8();                                /* extern */

void func_020a1664(void *arg0) {
    volatile u16 l4;
    volatile u16 l2;
    volatile u16 l0;
    volatile s32 lC;
    volatile s32 l8;
    u16 t;
    void *tp;

    tp                            = M2C_FIELD(arg0, void **, 0x1D0);
    lC                            = M2C_FIELD(tp, s32 *, 0xB8);
    l8                            = M2C_FIELD(tp, s32 *, 0xB0);
    l4                            = func_020985d8();
    t                             = l4;
    M2C_FIELD(arg0, u16 *, 0x36E) = t;
    l2                            = t;
    l0                            = t;
    M2C_FIELD(arg0, u16 *, 0x370) = t;
}
