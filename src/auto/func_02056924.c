#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */
M2C_UNK func_020675d8(s32, u8);                     /* extern */
extern M2C_UNK data_0210930c;

void func_02056924(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 2) != M2C_FIELD(temp_r0, u16 *, 0x182)) {
        return;
    }
    func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                  M2C_FIELD(arg1, u8 *, 3));
}
