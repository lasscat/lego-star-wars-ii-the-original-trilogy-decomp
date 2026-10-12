#include "m2c.h"

M2C_UNK func_020977f8();                            /* extern */
M2C_UNK func_02097bfc(u8, u8, u8, M2C_UNK);         /* extern */

void func_02097bcc(void *arg0) {
    func_020977f8();
    if (M2C_FIELD(arg0, u8 *, 0x3D) != 0) {
        return;
    }
    func_02097bfc(M2C_FIELD(arg0, u8 *, 0x3B), M2C_FIELD(arg0, u8 *, 0x3C), M2C_FIELD(arg0, u8 *, 0x1E), 1);
}
