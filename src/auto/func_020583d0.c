#include "m2c.h"

M2C_UNK func_02004b78(void *, M2C_UNK);             /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_020583d0(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x6B6) = 0;
    func_02004b78(temp_r0, 5);
}
