#include "m2c.h"

M2C_UNK func_020b3afc(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_027e0bd0;

void func_02056030(s32 arg0, u8 *arg1) {
    M2C_UNK var_r1;

    if (*arg1 != 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    func_020b3afc(&data_027e0bd0, var_r1);
}
