#include "m2c.h"

M2C_UNK func_020b94e4();                            /* extern */
M2C_UNK func_020b94fc();                            /* extern */
M2C_UNK func_020bb4ac(s8);                          /* extern */
extern M2C_UNK data_02104364;

void func_020b8f20(s8 arg0) {
    func_020b94e4();
    func_020bb4ac(arg0);
    func_020b94fc();
    M2C_FIELD(&data_02104364, s8 *, 9) = arg0;
}
