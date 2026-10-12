#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
s32 func_020d78c0(M2C_UNK *, s32, u16, s32, s32, s32); /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020ae388;

s32 func_020ae2f8(void) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x2D;
    if ((u32) (M2C_FIELD(&data_0210b320, s32 *, 0x20) - 4) <= 2U) {
        return 1;
    }
    func_020ad7a4(4);
    if (func_020d78c0(&func_020ae388, M2C_FIELD(&data_0210b320, s32 *, 0x38), (u16) M2C_FIELD(&data_0210b320, s32 *, 0x40), M2C_FIELD(&data_0210b320, s32 *, 0x24), (s32) (u16) M2C_FIELD(&data_0210b320, s32 *, 0x3C), 1) == 2) {
        return 1;
    }
    func_020ad8b4();
    return 0;
}
