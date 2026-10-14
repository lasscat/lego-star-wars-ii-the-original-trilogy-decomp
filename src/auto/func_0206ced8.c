#include "m2c.h"

M2C_UNK func_02053f60(void *, M2C_UNK);             /* extern */
M2C_UNK func_020540b4(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_02101b78;

void func_0206ced8(void *arg0) {
    func_02053f60((M2C_UNK *) ((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0x54) << 5)), 0x2000);
    func_020540b4((M2C_UNK *) ((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0x54) << 5)), 0, 0);
}
