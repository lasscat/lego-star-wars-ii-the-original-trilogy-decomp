#include "m2c.h"

M2C_UNK func_020e47fc(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK data_020ff3e0;
extern M2C_UNK func_0206afa4;

void *func_02085504(void *arg0) {
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff3e0;
    temp_r0                        = M2C_FIELD(arg0, void ***, 0x24);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, M2C_UNK(**)(), 4)(temp_r0);
    }
    temp_r0_2 = M2C_FIELD(arg0, void ***, 0x28);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, M2C_UNK(**)(), 4)(temp_r0_2);
    }
    temp_r0_3 = M2C_FIELD(arg0, void ***, 0x2C);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, M2C_UNK(**)(), 4)(temp_r0_3);
    }
    func_020e47fc(arg0 + 0x30, 8, 0xC, &func_0206afa4);
    return arg0;
}
