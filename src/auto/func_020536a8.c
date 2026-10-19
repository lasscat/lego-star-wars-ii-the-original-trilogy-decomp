#include "m2c.h"

M2C_UNK func_02053f44(void *, s32);                 /* extern */
M2C_UNK func_02053f60(void *, s32);                 /* extern */
extern M2C_UNK data_02101b78;

void func_020536a8(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_02053f44((M2C_UNK *) ((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)),
                      0x100 << M2C_FIELD(arg0, s32 *, 4));
    } else {
        func_02053f60((M2C_UNK *) ((s8 *) &data_02101b78 + (M2C_FIELD(arg0, s32 *, 0) << 5)),
                      0x100 << M2C_FIELD(arg0, s32 *, 4));
    }
}
