#include "m2c.h"

M2C_UNK func_02004b78(void *, u8);                  /* extern */
M2C_UNK func_02007268(void *);                      /* extern */
s32 func_0207f478(u8);                              /* extern */

void func_0204a544(void *arg0, void *arg1) {
    s32 temp_r0;
    u8 temp_r1;

    temp_r0 = func_0207f478(M2C_FIELD(arg0, u8 *, 0xB));
    temp_r1 = M2C_FIELD(arg0, u8 *, 9);
    if (temp_r1 == 4) {
        if (M2C_FIELD(arg1, s32 *, 0x6AC) == 0) {
            return;
        }
        func_02007268(arg1);
        return;
    }
    func_02004b78(arg1, M2C_FIELD((temp_r0 + (temp_r1 * 8)), u8 *, 6));
}
