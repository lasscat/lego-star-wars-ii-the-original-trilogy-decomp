#include "m2c.h"

M2C_UNK func_0202f9f4(void *);                      /* extern */
M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020b973c();                            /* extern */
extern M2C_UNK data_020fdf10;

void *func_020342b8(void *arg0) {
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdf10;
    temp_r2                        = M2C_FIELD(arg0, void **, 0x4C);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, s32 *, 8)   = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
        M2C_FIELD(arg0, void **, 0x4C) = NULL;
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
    func_0202f9f4(arg0);
    func_0205e84c(arg0);
    return arg0;
}
