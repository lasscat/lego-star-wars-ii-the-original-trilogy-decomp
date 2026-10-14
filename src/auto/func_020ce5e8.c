#include "m2c.h"

M2C_UNK func_020cc9c0(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_020ccb04(M2C_UNK);                     /* extern */
M2C_UNK func_020ce5cc(M2C_UNK);                     /* extern */
extern M2C_UNK data_0211575c;
extern M2C_UNK func_020ce660;

void func_020ce5e8(void) {
    if (M2C_FIELD(&data_0211575c, u16 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0211575c, u16 *, 0) = 1U;
    func_020ce5cc(0);
    M2C_FIELD(&data_0211575c, s32 *, 8)       = 0;
    M2C_FIELD(&data_0211575c, s32 *, 0xC)     = 0;
    M2C_FIELD((void *) 0x04000102, s16 *, 0)  = 0;
    M2C_FIELD((void *) 0x04000102, s16 *, -2) = 0;
    M2C_FIELD((void *) 0x04000102, s16 *, 0)  = 0xC1;
    func_020cc9c0(8, &func_020ce660);
    func_020ccb04(8);
    M2C_FIELD(&data_0211575c, s32 *, 4) = 0;
}
