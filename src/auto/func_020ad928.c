#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
s32 func_020ae868();                                /* extern */
extern M2C_UNK data_0210b320;

s32 func_020ad928(void) {
    if (M2C_FIELD(&data_0210b320, s32 *, 0x20) != 2) {
        return 1;
    }
    func_020ad7a4(3);
    return func_020ae868();
}
