#include "m2c.h"

M2C_UNK func_02086234(M2C_UNK *, u8, s32);          /* extern */
s32 func_02086244(M2C_UNK *, u8);                   /* extern */
extern M2C_UNK data_02104d90;

void func_02058694(s32 arg0, void *arg1) {
    func_02086234(&data_02104d90, M2C_FIELD(arg1, u8 *, 1), func_02086244(&data_02104d90, M2C_FIELD(arg1, u8 *, 0)));
}
