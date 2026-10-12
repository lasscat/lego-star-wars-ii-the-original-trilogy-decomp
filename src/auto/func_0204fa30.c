#include "m2c.h"

u16 func_0204fa30(void *arg0) {
    void *temp_r0;

    if ((M2C_FIELD(arg0, u8 *, 0) != 0) && (M2C_FIELD(arg0, u8 *, 1) == 0)) {
        temp_r0 = M2C_FIELD(arg0, void **, 0x10);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, u16 *, 2);
        }
    }
    return 6U;
}
