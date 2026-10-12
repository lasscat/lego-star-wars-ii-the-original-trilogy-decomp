#include "m2c.h"

M2C_UNK func_020ad8b4();                            /* extern */
M2C_UNK func_020addf0(M2C_UNK);                     /* extern */
s32 func_020d73a0(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020ae608;

s32 func_020ae5a0(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s32 *, 0x30) = 0;
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x10;
    temp_r0 = func_020d73a0(&func_020ae608);
    if (temp_r0 == 0) {
        return 1;
    }
    if (temp_r0 != 2) {
        func_020ad8b4();
        return 0;
    }
    func_020addf0(0x11);
    if (M2C_FIELD(&data_0210b320, s32 *, 0x30) == 0) {
        return 1;
    }
    return 0;
}
