#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_02062748();                            /* extern */
M2C_UNK func_020940c4();                            /* extern */

void func_020941f0(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0xC);
    if (((u32) (M2C_FIELD(temp_r2, u16 *, 0x14E) << 0x1E) >> 0x1F) == 1) {
        func_020940c4(arg0);
        return;
    }
    if ((M2C_FIELD(temp_r2, s32 *, 8) & 0x802) && (arg0 != NULL)) {
        func_02062748(arg0);
        func_0205e84c(arg0);
    }
}
