#include "m2c.h"

M2C_UNK func_02086234(M2C_UNK *, u8, u8);           /* extern */
extern M2C_UNK data_02104d90;

void func_02058674(s32 arg0, void *arg1) {
    func_02086234(&data_02104d90, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 0));
}
