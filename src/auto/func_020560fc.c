#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */
M2C_UNK func_02098440(u16 *, u8);                   /* extern */

void func_020560fc(M2C_UNK arg0, void *arg1) {
    u16 sp2;
    volatile u16 sp0;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    func_02098440(&sp2, M2C_FIELD(arg1, u8 *, 2));
    sp0 = sp2;
    if (M2C_FIELD(temp_r0, u16 *, 0xCA) != sp2) {
        M2C_FIELD(temp_r0, u16 *, 0xCA) = sp2;
        M2C_FIELD(temp_r0, s8 *, 0xD0)  = 1;
    }
}
