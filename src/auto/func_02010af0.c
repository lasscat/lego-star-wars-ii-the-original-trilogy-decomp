#include "m2c.h"

s32 func_0205c69c(void *, void *, void *, s32); /* extern */

void func_02010af0(void *arg0) {
    s32 sp0;
    s32 *p;
    s32 *temp_r0;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 0x190);
    if (temp_r1 == NULL) {
        return;
    }
    if ((M2C_FIELD(temp_r1, u8 *, 0x2E) == 0) && (M2C_FIELD(temp_r1, u8 *, 0x2F) == 0)) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s32 **, 0x148);
    p       = &sp0;
    if (temp_r0 != NULL) {
        sp0 = *temp_r0;
    } else {
        sp0 = 0;
    }
    if (func_0205c69c(M2C_FIELD(arg0, void **, 0x190), arg0, arg0 + 0x8C, *p >> 0xC) == 0) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) | 0x200);
}
