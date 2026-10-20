/* Reconstructed from USA ARM9 at 0x02058280 (96 bytes).
 * Names and types are inferred from the binary.
 *
 * The original binary stores the shifted nibble into a 4-byte stack slot
 * (str r2, [sp]) immediately before the call and never reads it back, so the
 * slot is modelled as a volatile local (the same technique used by the
 * already matched siblings func_02057ac4 / func_020577e0 / func_02057788).
 * The 4th argument of func_0202d9ac cannot be the source of that store:
 * every available mwccarm version passes argument 4 in r3.
 */
#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */
void func_0202d9ac(M2C_UNK, M2C_UNK, u32);          /* extern */

void func_02058280(M2C_UNK arg0, u8 *arg1) {
    void *a;
    void *b;
    u32 v;

    a = func_02067080(arg0, arg1[0], arg1[1]);
    b = func_02067080(arg0, arg1[2], arg1[3]);
    if (a != NULL && b != NULL) {
        volatile u32 sp0;

        v   = arg1[4] << 12;
        sp0 = v;
        func_0202d9ac(a, b, v);
    }
}
