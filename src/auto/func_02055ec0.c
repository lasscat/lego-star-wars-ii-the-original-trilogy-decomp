#include "m2c.h"

void **func_02067080(void *, u8, u8);               /* extern */
M2C_UNK func_0206769c(s32, u8, u8);                 /* extern */

void func_02055ec0(void *arg0, void *arg1) {
    void **temp_r0;

    if (M2C_FIELD(arg1, u8 *, 2) != 0) {
        temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
        if (temp_r0 == NULL) {
            return;
        }
        M2C_FIELD(*temp_r0, M2C_UNK (**)(void **, M2C_UNK), 0x40)(temp_r0, 0);
        return;
    }
    func_0206769c(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
}
