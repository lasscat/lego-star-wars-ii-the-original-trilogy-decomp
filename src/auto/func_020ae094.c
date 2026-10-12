#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
M2C_UNK func_020ad8b4(u16);                         /* extern */
extern M2C_UNK data_0210b320;

void func_020ae094(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad7a4(9);
        func_020ad8b4(M2C_FIELD(arg0, u16 *, 2));
        return;
    }
    func_020ad7a4(1);
    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x1D;
}
