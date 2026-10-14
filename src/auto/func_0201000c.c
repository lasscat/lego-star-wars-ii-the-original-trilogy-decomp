#include "m2c.h"

M2C_UNK func_02017b54(void *);                      /* extern */
M2C_UNK func_0205c368(s32);                         /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_0209f494(void *);                      /* extern */
extern M2C_UNK data_020fcf78;

void *func_0201000c(void *arg0) {
    s32 temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcf78;
    temp_r4                        = M2C_FIELD(arg0, s32 *, 0x190);
    if (temp_r4 != 0) {
        func_0205c368(temp_r4);
        func_0205e84c(temp_r4);
    }
    func_0209f494(arg0 + 0xD4);
    func_02017b54(arg0);
    return arg0;
}
