#include "m2c.h"

void func_02074f50(void **arg0, void *arg1) {
    void *temp_r2;
    void *temp_r2_2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x34);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0x38) = (void *) M2C_FIELD(arg1, void **, 0x38);
    } else {
        *arg0 = M2C_FIELD(arg1, void **, 0x38);
    }
    temp_r2_2 = M2C_FIELD(arg1, void **, 0x38);
    if (temp_r2_2 != NULL) {
        M2C_FIELD(temp_r2_2, void **, 0x34) = (void *) M2C_FIELD(arg1, void **, 0x34);
    }
}
