#include "m2c.h"

M2C_UNK func_020120ac();                            /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fd7a8;

void *func_02022368(void *arg0) {
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd7a8;
    temp_r2 = M2C_FIELD(arg0, void **, 0x230);
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
    func_020120ac(arg0);
    func_0205e84c(arg0);
    return arg0;
}
