#include "m2c.h"

M2C_UNK func_02060158(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_020867ec(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

void func_0206aecc(void *arg0) {
    if (func_020867ec(&data_02104d90, 4) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 8) == 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 6) = 0;
    M2C_FIELD(arg0, s8 *, 7) = 1;
    func_02060158(&data_02102900, 0, 0x13, 0);
}
