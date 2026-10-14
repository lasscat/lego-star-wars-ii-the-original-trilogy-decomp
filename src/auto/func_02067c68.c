#include "m2c.h"

M2C_UNK func_02053f60(void *, s32);                 /* extern */
s32 func_02067d20();                                /* extern */
extern M2C_UNK data_02101b78;

void func_02067c68(void *arg0) {
    if (func_02067d20() == 0) {
        return;
    }
    func_02053f60((M2C_UNK *) ((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)), 0x2000 << M2C_FIELD(arg0, s32 *, 4));
}
