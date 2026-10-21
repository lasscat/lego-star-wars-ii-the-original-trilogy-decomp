#include "m2c.h"

extern void func_02047b94(void *, s32);

void func_02047b38(M2C_UNK arg0) {
    func_02047b94(arg0, 1);
    if (M2C_FIELD(arg0, u8 *, 0xe) == 0) {
        M2C_FIELD(arg0, u8 *, 0xd) = 0;
        return;
    }
    M2C_FIELD(arg0, u8 *, 0xd) = 5;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32),
              0x24)(M2C_FIELD(arg0, void **, 4), 4, 0, 1, 0);
}
