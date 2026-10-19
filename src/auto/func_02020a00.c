#include "m2c.h"

void func_02020a00(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1D8) = (s8) (M2C_FIELD(arg0, s8 *, 0x1D8) + 1);
    if (M2C_FIELD(arg0, u16 *, 0x212) == 0x143) {
        M2C_FIELD(arg0, s8 *, 0x1D8) = (s8) M2C_FIELD(arg0, u8 *, 0x1DC);
    }
    if ((s32) M2C_FIELD(arg0, s8 *, 0x1D8) < (s32) M2C_FIELD(arg0, u8 *, 0x1DC)) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1BC) != 0) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x1BC) = 1U;
    if (M2C_FIELD(arg0, u16 *, 0x212) == 0x143) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0x24)(arg0, 0x56, 0, 1, 0);
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0x24)(arg0, 0x35, 0, 1, 0);
}
