#include "m2c.h"

void *func_02017800(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_020261fc();                            /* extern */

void func_0201f58c(M2C_UNK arg0, s8 arg1) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_02017800(arg0, 0);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s8 *, 0x216) = arg1;
        func_020261fc();
    }
    temp_r0_2 = func_02017800(arg0, 1);
    if (temp_r0_2 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0_2, s8 *, 0x216) = arg1;
    func_020261fc();
}
