#include "m2c.h"

M2C_UNK func_020cf624();                            /* extern */
M2C_UNK func_020d5018(u16);                         /* extern */
extern M2C_UNK data_021157c8;

void func_020cf660(void) {
    func_020cf624();
    func_020d5018(M2C_FIELD(&data_021157c8, u16 *, 4));
}
