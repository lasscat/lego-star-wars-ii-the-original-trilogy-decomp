#include "m2c.h"

u8 func_0202cb68(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x24);
    if (temp_r0 != NULL) {
        return M2C_FIELD(temp_r0, u8 *, 3);
    }
    return 3U;
}
