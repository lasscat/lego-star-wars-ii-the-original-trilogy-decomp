#include "m2c.h"

s32 func_020d6b1c(M2C_UNK *);                       /* extern */
s32 func_020d8798(M2C_UNK *, u16, u16, u16, s32);   /* extern */
M2C_UNK func_020dce78(M2C_UNK, s32);                /* extern */
extern M2C_UNK data_0210156c;
extern M2C_UNK func_020db3c8;

void func_020db378(void) {
    func_020dce78(0x80, func_020d6b1c(&func_020db3c8));
    func_020dce78(0x1D, func_020d8798(&func_020db3c8, M2C_FIELD(&data_0210156c, u16 *, 6), M2C_FIELD(&data_0210156c, u16 *, 2), M2C_FIELD(&data_0210156c, u16 *, 0), (s32) M2C_FIELD(&data_0210156c, u16 *, 4)));
}
