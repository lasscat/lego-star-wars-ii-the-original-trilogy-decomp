#include "m2c.h"

M2C_UNK func_02001900(void *);                      /* extern */
M2C_UNK func_0201a8bc(void *);                      /* extern */
M2C_UNK func_0201b48c();                            /* extern */
M2C_UNK func_02060e6c(void *);                      /* extern */
extern M2C_UNK data_020fd0f0;

void *func_0201ac58(void *arg0) {
    u32 temp_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd0f0;
    func_0201b48c();
    func_02060e6c(arg0);
    temp_r0 = (u32) (M2C_FIELD(arg0, s32 *, 0x10) << 0x16) >> 0x1E;
    if ((temp_r0 != 1) && (temp_r0 != 3)) {

    } else {
        func_0201a8bc(arg0);
    }
    func_02001900(arg0);
    return arg0;
}
