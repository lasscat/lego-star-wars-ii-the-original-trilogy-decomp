#include "m2c.h"

s32 func_020cdf70(M2C_UNK);                         /* extern */
s32 func_020ce054(M2C_UNK);                         /* extern */
M2C_UNK func_020ce0fc(M2C_UNK, s32);                /* extern */
M2C_UNK func_020ce110(M2C_UNK, s32);                /* extern */
extern s32 data_021156a0;

void func_020cddd8(void) {
    if (data_021156a0 != 0) {
        return;
    }
    data_021156a0 = 1;
    func_020ce0fc(0, func_020cdf70(0));
    func_020ce110(0, func_020ce054(0));
    func_020ce110(2, 0);
    func_020ce0fc(2, 0);
    func_020ce0fc(3, func_020cdf70(3));
    func_020ce110(3, func_020ce054(3));
    func_020ce0fc(4, func_020cdf70(4));
    func_020ce110(4, func_020ce054(4));
    func_020ce0fc(5, func_020cdf70(5));
    func_020ce110(5, func_020ce054(5));
    func_020ce0fc(6, func_020cdf70(6));
    func_020ce110(6, func_020ce054(6));
}
