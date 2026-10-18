/* Reconstructed from USA ARM9 at 0x0200bfc0 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0200bfc0(void *arg0, s32 *arg1) {
    s32 v;

    if (arg0 == NULL) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1D0)  = 1;
    v                             = *arg1;
    M2C_FIELD(arg0, s32 *, 0x1CC) = v;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK(**)(void *, s32), 0x44)(arg0, v);
}
