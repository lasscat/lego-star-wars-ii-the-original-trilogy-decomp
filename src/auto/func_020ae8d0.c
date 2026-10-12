#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
extern M2C_UNK data_0210b320;

void func_020ae8d0(void *arg0) {
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x17;
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4();
        return;
    }
    func_020ad7a4(1);
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x17;
}
