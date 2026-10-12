#include "m2c.h"

s32 func_020cd8c0();                                /* extern */
s32 func_020cdf70(M2C_UNK);                         /* extern */
s32 func_020ce054(M2C_UNK);                         /* extern */
M2C_UNK func_020ce0fc(M2C_UNK, s32);                /* extern */
M2C_UNK func_020ce110(M2C_UNK, s32);                /* extern */
M2C_UNK func_020ce3c8(s32);                         /* extern */
M2C_UNK func_020ce3d0(s32);                         /* extern */
extern M2C_UNK data_021156a0;

void func_020cdedc(void) {
    func_020ce0fc(2, func_020cdf70(2));
    func_020ce110(2, func_020ce054(2));
    if ((M2C_FIELD(&data_021156a0, s32 *, 4) != 0) && ((func_020cd8c0() & 3) != 1)) {
        return;
    }
    func_020ce3c8(0x0200002B);
    func_020ce3d0(0x023E0021);
}
