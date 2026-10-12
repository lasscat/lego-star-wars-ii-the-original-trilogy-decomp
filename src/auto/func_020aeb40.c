#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
s32 func_020d78c0(M2C_UNK *, s32, u16, s32, s32, s32); /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020aeba4;

s32 func_020aeb40(void) {
    if (func_020d78c0(&func_020aeba4, M2C_FIELD(&data_0210b320, s32 *, 0x38), (u16) M2C_FIELD(&data_0210b320, s32 *, 0x40), M2C_FIELD(&data_0210b320, s32 *, 0x24), (s32) (u16) M2C_FIELD(&data_0210b320, s32 *, 0x3C), 1) == 2) {
        return 1;
    }
    func_020ad8b4();
    return 0;
}
