#include "m2c.h"

M2C_UNK func_020b4080(M2C_UNK);                     /* extern */
M2C_UNK func_020b94e4();                            /* extern */
M2C_UNK func_020b94fc();                            /* extern */
extern M2C_UNK data_0210db14;

void func_020b9204(void) {
    if (M2C_FIELD(&data_0210db14, u8 *, 0xA) & 0x20) {
        return;
    }
    func_020b94e4();
    func_020b4080(4);
    M2C_FIELD(&data_0210db14, u8 *, 0xA) = (u8) (M2C_FIELD(&data_0210db14, u8 *, 0xA) & ~1);
    M2C_FIELD(&data_0210db14, s8 *, 9) = 0x1D;
    func_020b94fc();
}
