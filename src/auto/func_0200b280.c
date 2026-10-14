#include "m2c.h"

M2C_UNK func_02017b54(void *);                      /* extern */
M2C_UNK func_020e47fc(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020fcd70;
extern M2C_UNK func_0200b24c;

void *func_0200b280(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcd70;
    temp_r1                        = M2C_FIELD(arg0, void **, 0xD4);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 2);
    }
    func_020e47fc(arg0 + 0xD8, 3, 8, &func_0200b24c);
    func_02017b54(arg0);
    return arg0;
}
