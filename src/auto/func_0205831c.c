#include "m2c.h"

M2C_UNK func_0208fa1c(s32, u8, u8, s32);            /* extern */
extern M2C_UNK data_0210930c;

void func_0205831c(s32 arg0, void *arg1) {
    func_0208fa1c(M2C_FIELD(&data_0210930c, s32 *, 0x68), M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 0),
                  M2C_FIELD(arg1, u8 *, 2) * 0x1E);
}
