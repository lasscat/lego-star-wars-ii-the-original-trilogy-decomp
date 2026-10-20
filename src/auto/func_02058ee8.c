#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8); /* extern */
void *func_0202c01c(void *, void *);  /* extern */

void func_02058ee8(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    func_0202c01c(temp_r0 + 0x5E0, temp_r0);
}
