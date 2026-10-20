#include "m2c.h"

extern M2C_UNK data_0210930c;
extern void func_02091dc4(M2C_UNK *a0, u8 a1, s32 a2);

void func_02015dcc(u8 *self, u8 a1, u8 a2, u8 a3, u8 a4, u8 a5) {
    self[0x1df] = a1;
    self[0x1de] = a2;
    self[0x1d9] = a3;
    self[0x1da] = a4;
    self[0x1db] = a5;
    func_02091dc4(&data_0210930c, self[0x1db], 0);
}
