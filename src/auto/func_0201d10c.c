#include "m2c.h"

M2C_UNK func_020100a4(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
extern M2C_UNK data_020fd220;

void *func_0201d10c(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd220;
    temp_r1                        = M2C_FIELD(arg0, void **, 0x1C8);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 0x384) = (s32) (M2C_FIELD(temp_r1, s32 *, 0x384) | 0x80000000);
    }
    func_020100a4(arg0);
    func_0205e84c(arg0);
    return arg0;
}
