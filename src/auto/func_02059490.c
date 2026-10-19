/* Reconstructed from USA ARM9 at 0x02059490 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);

void func_02059490(M2C_UNK arg0, void *arg1) {
    void *p = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2));
    if (p == NULL) {
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 0) != 0) {
        M2C_FIELD(p, s32 *, 8) |= 0x800000;
        return;
    }
    M2C_FIELD(p, s32 *, 8) &= ~0x800000;
}
