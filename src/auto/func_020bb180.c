#include "m2c.h"

M2C_UNK func_020b9d94();                            /* extern */
M2C_UNK SND_StopTimer(u16, u8, u8, M2C_UNK);        /* extern */
M2C_UNK SND_WaitForFreeCommand(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210db84;
extern M2C_UNK data_0210e184;

void func_020bb180(void) {
    if (M2C_FIELD(&data_0210db84, s32 *, 0x9C) & 4) {
        return;
    }
    func_020b9d94();
    SND_WaitForFreeCommand(1);
    SND_StopTimer(M2C_FIELD(&data_0210e184, u16 *, 0x64), M2C_FIELD(&data_0210db84, u8 *, 0x666),
                  M2C_FIELD(&data_0210db84, u8 *, 0x667), 0);
    M2C_FIELD(&data_0210db84, s32 *, 0x9C) = (s32) (M2C_FIELD(&data_0210db84, s32 *, 0x9C) | 4);
}
