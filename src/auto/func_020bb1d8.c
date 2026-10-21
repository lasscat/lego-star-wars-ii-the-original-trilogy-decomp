#include "m2c.h"

extern M2C_UNK data_0210db84;
extern M2C_UNK data_0210e184;
extern M2C_UNK data_0210e194;
extern M2C_UNK data_0210e1c4;

M2C_UNK SND_StartTimer(u16, u8, u8, M2C_UNK);       /* extern */
M2C_UNK SND_WaitForFreeCommand(M2C_UNK);            /* extern */
M2C_UNK func_0205e624(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b9de4();                            /* extern */

void func_020bb1d8(void) {
    if (!(M2C_FIELD(&data_0210db84, volatile s32 *, 0x9C) & 4)) {
        return;
    }
    M2C_FIELD(&data_0210db84, volatile s32 *, 0x9C) = (s32) (M2C_FIELD(&data_0210db84, volatile s32 *, 0x9C) & ~4);
    if (M2C_FIELD(&data_0210db84, u8 *, 0x5D8) != 7) {
        M2C_FIELD(&data_0210db84, s32 *, 0x608) = 0;
        func_0205e624(&data_0210e194, 0, 0x20);
        M2C_FIELD(&data_0210db84, s32 *, 0x638) = 0;
        func_0205e624(&data_0210e1c4, 0, 0x20);
    }
    SND_WaitForFreeCommand(5);
    func_020b9de4();
    SND_StartTimer(M2C_FIELD(&data_0210e184, u16 *, 0x64), M2C_FIELD(&data_0210db84, u8 *, 0x666),
                   M2C_FIELD(&data_0210db84, u8 *, 0x667), 0);
}
