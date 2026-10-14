#include "m2c.h"

M2C_UNK func_0205e84c(void *);                      /* extern */
M2C_UNK func_020b973c();                            /* extern */
extern M2C_UNK data_020fe3a8;

void *func_02048238(void *arg0) {
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe3a8;
    if (M2C_FIELD(arg0, s32 *, 0x24) != 0) {
        func_020b973c();
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
    }
    temp_r2 = M2C_FIELD(arg0, void **, 0x20);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, s32 *, 0x384) = (s32) (M2C_FIELD(temp_r2, s32 *, 0x384) | 0x80000000);
        M2C_FIELD(arg0, void **, 0x20)   = NULL;
    }
    func_0205e84c(arg0);
    return arg0;
}
