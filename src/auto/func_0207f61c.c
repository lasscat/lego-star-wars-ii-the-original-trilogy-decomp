#include "m2c.h"

void *func_02067080(void *, s32, s32);              /* extern */
M2C_UNK func_020675d8(s32, u16);                    /* extern */
extern M2C_UNK data_0210930c;

s32 func_0207f61c(void *arg0) {
    void *temp_r0;

    temp_r0 = func_02067080(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), M2C_FIELD(arg0, s32 *, 4),
                            M2C_FIELD(arg0, s32 *, 8));
    if ((temp_r0 != NULL) && ((s32) M2C_FIELD(temp_r0, s16 *, 0x6B6) <= (s32) M2C_FIELD(arg0, u16 *, 0xC))) {
        func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                      M2C_FIELD(arg0, u16 *, 0xE));
        return 1;
    }
    return 0;
}
