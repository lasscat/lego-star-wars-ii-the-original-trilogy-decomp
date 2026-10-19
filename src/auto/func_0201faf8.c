#include "m2c.h"

extern M2C_UNK data_020f03b4;

void func_0201faf8(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x1BC) == 1) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x1BC)  = 4U;
    M2C_FIELD(arg0, s32 *, 0x194) = *((s32 *) ((s8 *) &data_020f03b4 + (M2C_FIELD(arg0, u16 *, 0x212) * 0x10)));
    M2C_FIELD(arg0, u16 *, 0x14E) = (u16) ((M2C_FIELD(arg0, u16 *, 0x14E) & ~1) | 1);
    M2C_FIELD(arg0, u16 *, 0x14E) = (u16) (M2C_FIELD(arg0, u16 *, 0x14E) & ~2);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0x24)(arg0, 0x56, 0, 1, 1);
}
