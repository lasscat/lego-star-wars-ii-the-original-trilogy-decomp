#include "m2c.h"

M2C_UNK func_020900ec(void *, M2C_UNK, M2C_UNK, s32 *); /* extern */
M2C_UNK func_020901d0(void *);                      /* extern */

void func_02090140(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 sp0;

    sp0 = 0;
    func_020900ec(arg0, arg1, arg2, &sp0);
    M2C_FIELD(arg0, s32 *, 0x3D4) = (s32) (M2C_FIELD(arg0, s32 *, 0x3D4) | sp0);
    func_020901d0(arg0);
}
