#include "m2c.h"

M2C_UNK func_020120ac(void *);                      /* extern */
extern M2C_UNK data_020fd670;

void *func_02021098(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd670;
    temp_r1 = M2C_FIELD(arg0, void **, 0x218);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 0x384) = (s32) (M2C_FIELD(temp_r1, s32 *, 0x384) | 0x80000000);
    }
    func_020120ac(arg0);
    return arg0;
}
