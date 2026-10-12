#include "m2c.h"

M2C_UNK func_020b94e4();                            /* extern */
M2C_UNK func_020b94fc();                            /* extern */
M2C_UNK func_020bb180();                            /* extern */
extern u8 data_0210db14;

void func_020b8df0(void) {
    if (data_0210db14 != 1) {
        return;
    }
    func_020b94e4();
    func_020bb180();
    func_020b94fc();
}
