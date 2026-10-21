#include "m2c.h"

extern void func_02022fa0(M2C_UNK);

/* Reconstructed from USA ARM9 at 0x02023830 (64 bytes).
 * a0 points at the object; the fields used are 0x212 (u16 state),
 * 0x246 (u16 new value), 0xca (u16 current value) and 0xd0 (u8 flag). */
void func_02023830(s32 a0) {
    volatile u16 sp0;
    u16 v;

    if (*(u16 *) (a0 + 0x212) != 0x15d) {
        return;
    }
    v   = *(u16 *) (a0 + 0x246);
    sp0 = v;
    if (*(u16 *) (a0 + 0xca) != v) {
        *(u16 *) (a0 + 0xca) = v;
        *(u8 *) (a0 + 0xd0)  = 1;
    }
    func_02022fa0(a0);
}
