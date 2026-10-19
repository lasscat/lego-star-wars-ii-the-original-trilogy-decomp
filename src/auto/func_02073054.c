#include "m2c.h"

extern M2C_UNK data_020feb88;
extern void **data_021092f4;
extern void **data_0210b348;
extern s32 data_027e02a8;

void func_02073054(s32 arg0) {
    M2C_FIELD(&data_020feb88, s32 *, 0) = arg0;
    if (!(data_027e02a8 & 0x40)) {
        return;
    }
    if (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) != 0) {
        return;
    }
    if ((s32) M2C_FIELD(&data_020feb88, s32 *, 0) < (s32) (M2C_FIELD(&data_020feb88, s32 *, 4) - 1)) {
        return;
    }
    M2C_FIELD(*data_0210b348, M2C_UNK(**)(void **, M2C_UNK), 0x4C)(data_0210b348, 0);
}
