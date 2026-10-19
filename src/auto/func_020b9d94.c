#include "m2c.h"

M2C_UNK SND_StopTimer(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SND_WaitForFreeCommand(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210dc20;

void func_020b9d94(void) {
    if (M2C_FIELD(&data_0210dc20, s32 *, 0x498) == 0) {
        return;
    }
    if (M2C_FIELD(&data_0210dc20, s32 *, 0x498) & 0x20) {
        return;
    }
    SND_WaitForFreeCommand(1);
    SND_StopTimer(0xA, 3, 1, 0);
    M2C_FIELD(&data_0210dc20, s32 *, 0x498) = (s32) (M2C_FIELD(&data_0210dc20, s32 *, 0x498) | 0x20);
}
