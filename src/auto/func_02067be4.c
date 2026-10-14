#include "m2c.h"

M2C_UNK func_02053f44(void *, s32);                 /* extern */
M2C_UNK func_02067ca0(void *, M2C_UNK, u8, u8, s32); /* extern */
extern M2C_UNK data_02101b78;

void func_02067be4(void *arg0, s32 arg1, s32 arg2, M2C_UNK arg3, u8 arg4, u8 arg5, u8 arg6) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 4) = arg2;
    func_02053f44((M2C_UNK *) ((s8 *) &data_02101b78 + (arg1 << 5)), 0x2000 << arg2);
    func_02067ca0(arg0, arg3, arg4, arg5, (s32) arg6);
}
