#include "m2c.h"

M2C_UNK func_0205e0a0();                            /* extern */

void *func_0205e018(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x18);
    if (temp_r2 != NULL) {
        M2C_FIELD(arg0, void **, 0x18) = (void *) M2C_FIELD(temp_r2, void **, 4);
        M2C_FIELD(temp_r2, s32 *, 0) = 0;
        M2C_FIELD(temp_r2, void **, 4) = NULL;
        M2C_FIELD(temp_r2, s32 *, 8) = 0;
        M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 1);
        return temp_r2;
    }
    func_0205e0a0(arg0);
    return func_0205e018(arg0);
}
