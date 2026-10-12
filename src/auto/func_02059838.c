#include "m2c.h"

M2C_UNK func_0202c2fc(void *);                      /* extern */
void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_02059838(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (!(M2C_FIELD(temp_r0, u16 *, 0xC) & 3)) {
        return;
    }
    func_0202c2fc(temp_r0 + 0x5E0);
}
