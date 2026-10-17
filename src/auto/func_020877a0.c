#include "m2c.h"

M2C_UNK func_0200fa74(s32);                         /* extern */
M2C_UNK func_02053f80(M2C_UNK *);                   /* extern */
M2C_UNK func_02055c48(M2C_UNK);                     /* extern */
M2C_UNK func_02072e54();                            /* extern */
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02101b98;
extern s32 data_027e02a4;

void func_020877a0(void *arg0) {
    void **temp_r0;
    void **temp_r0_2;
    void **temp_r0_3;

    temp_r0 = M2C_FIELD(arg0, void ***, 0xC4);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, M2C_UNK(**)(), 4)(temp_r0);
    }
    M2C_FIELD(arg0, void ***, 0xC4) = NULL;
    temp_r0_2                       = M2C_FIELD(arg0, void ***, 0xD0);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(*temp_r0_2, M2C_UNK(**)(), 4)(temp_r0_2);
    }
    M2C_FIELD(arg0, void ***, 0xD0) = NULL;
    temp_r0_3                       = M2C_FIELD(arg0, void ***, 0xD4);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(*temp_r0_3, M2C_UNK(**)(), 4)(temp_r0_3);
    }
    M2C_FIELD(arg0, void ***, 0xD4) = NULL;
    func_02053f80(&data_02101b98);
    func_0200fa74((data_027e02a4 * 0x38) + (s32) &data_021019f4);
    func_02072e54();
    func_02055c48(1);
}
