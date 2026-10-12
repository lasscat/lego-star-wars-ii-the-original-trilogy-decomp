#include "m2c.h"

M2C_UNK func_02017b54(void *);                      /* extern */
M2C_UNK func_0205a044(s32);                         /* extern */
M2C_UNK func_0205a99c(s32);                         /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
extern M2C_UNK data_020fd0a0;

void *func_02019af8(void *arg0) {
    s32 temp_r4;
    s32 temp_r4_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd0a0;
    temp_r4 = M2C_FIELD(arg0, s32 *, 0xD4);
    if (temp_r4 != 0) {
        func_0205a044(temp_r4);
        func_0205e84c(temp_r4);
    }
    temp_r4_2 = M2C_FIELD(arg0, s32 *, 0xD8);
    if (temp_r4_2 != 0) {
        func_0205a99c(temp_r4_2);
        func_0205e84c(temp_r4_2);
    }
    func_02017b54(arg0);
    return arg0;
}
