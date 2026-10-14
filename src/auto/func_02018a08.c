#include "m2c.h"

M2C_UNK func_020100a4(void *);                      /* extern */
extern M2C_UNK data_020fd060;

void *func_02018a08(void *arg0) {
    void *temp_r2;
    void *temp_r2_2;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd060;
    temp_r2                        = M2C_FIELD(arg0, void **, 0x1C8);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, u8 *, 8)     = (u8) (M2C_FIELD(temp_r2, u8 *, 8) + 1);
        M2C_FIELD(arg0, void **, 0x1C8) = NULL;
    }
    temp_r2_2 = M2C_FIELD(arg0, void **, 0x1CC);
    if (temp_r2_2 != NULL) {
        M2C_FIELD(temp_r2_2, u8 *, 8)   = (u8) (M2C_FIELD(temp_r2_2, u8 *, 8) + 1);
        M2C_FIELD(arg0, void **, 0x1CC) = NULL;
    }
    func_020100a4(arg0);
    return arg0;
}
