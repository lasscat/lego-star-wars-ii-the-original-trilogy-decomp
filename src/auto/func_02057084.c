#include "m2c.h"

M2C_UNK func_02086204(M2C_UNK *, u16);              /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */
M2C_UNK func_020675d8(s32, u8);                     /* extern */
extern M2C_UNK data_02104d90;

void func_02057084(void *arg0, void *arg1) {
    if (func_02086204(&data_02104d90, M2C_FIELD(arg1, u16 *, 0)) != 0) {
        func_0206763c(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 2));
        func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 3));
        return;
    }
    func_0206763c(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 4));
    func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 5));
}
