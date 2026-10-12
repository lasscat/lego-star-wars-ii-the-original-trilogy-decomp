#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210b320;

s32 func_020ae498(void) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x2A;
    func_020ad7a4(6);
    return 1;
}
