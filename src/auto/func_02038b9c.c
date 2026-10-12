#include "m2c.h"

M2C_UNK func_02016634(void *);                      /* extern */
extern M2C_UNK data_020fe0b4;
extern M2C_UNK data_0210930c;

void *func_02038b9c(void *arg0) {
    void *temp_r2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe0b4;
    temp_r2 = M2C_FIELD(arg0, void **, 0x1C);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
        M2C_FIELD(arg0, void **, 0x1C) = NULL;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s8 *, 0x1AD) = 0;
    }
    if (M2C_FIELD(&data_0210930c, s32 *, 0x68) != 0) {
        func_02016634(M2C_FIELD(arg0, void **, 0x10));
    }
    return arg0;
}
