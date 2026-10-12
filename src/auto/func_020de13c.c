#include "m2c.h"

M2C_UNK func_020de188(M2C_UNK);                     /* extern */
M2C_UNK func_020e4560();                            /* extern */
extern M2C_UNK data_0211ea50;

void func_020de13c(M2C_UNK arg0) {
    if (M2C_FIELD(&data_0211ea50, s32 *, 0xC) == 0) {
        func_020e4560();
        if (M2C_FIELD(&data_0211ea50, M2C_UNK (**)(), 4) != NULL) {
            M2C_FIELD(&data_0211ea50, M2C_UNK (**)(), 4)();
            M2C_FIELD(&data_0211ea50, M2C_UNK (**)(), 4) = NULL;
        }
    }
    func_020de188(arg0);
}
