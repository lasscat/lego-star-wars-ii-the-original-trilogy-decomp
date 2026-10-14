#include "m2c.h"

M2C_UNK func_020120ac(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fda18;

void *func_020252ec(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fda18;
    temp_r1                        = M2C_FIELD(arg0, void **, 0x21C);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 2);
    }
    func_020120ac(arg0);
    func_0205e84c(arg0);
    return arg0;
}
