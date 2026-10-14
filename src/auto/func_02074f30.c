#include "m2c.h"

void *func_02074f30(void **arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = *arg0;
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x38);
    *arg0   = temp_r1;
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 0x34) = 0;
    }
    return temp_r2;
}
