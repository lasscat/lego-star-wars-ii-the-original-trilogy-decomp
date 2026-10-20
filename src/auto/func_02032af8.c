#include "m2c.h"

void func_02032af8(M2C_UNK arg0) {
    u16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u16 *, 0x16);
    if (temp_r1 == 0xf5) {
        return;
    }
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32),
              0x24)(M2C_FIELD(arg0, void **, 4), temp_r1, 1, 1, 0);
}
