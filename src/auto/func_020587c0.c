#include "m2c.h"

M2C_UNK func_02090888(s32, s32, s32, u8, s32);      /* extern */
extern M2C_UNK data_0210930c;

void func_020587c0(s32 arg0, void *arg1) {
    func_02090888(M2C_FIELD(&data_0210930c, s32 *, 0x68), M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, u8 *, 9), (s32) M2C_FIELD(arg1, u8 *, 8));
}
