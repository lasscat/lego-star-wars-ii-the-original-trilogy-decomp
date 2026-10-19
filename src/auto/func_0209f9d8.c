/* Reconstructed from USA ARM9 at 0x0209f9d8 (80 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_0209f9d8(void *arg0) {
    s32 sp4;
    volatile s32 sp0;
    s32 *sp4p;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 0x74);
    if (temp_r1 == NULL) {
        return;
    }
    sp4p = &sp4;
    if (temp_r1 == NULL) {
        sp4 = 0;
    } else {
        sp4 = M2C_FIELD(M2C_FIELD(temp_r1, void **, 8), u16 *, 4) << 0xC;
    }
    sp0                                                 = *sp4p;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x74), s32 *, 0) = *sp4p;
}
