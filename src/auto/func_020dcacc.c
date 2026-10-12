#include "m2c.h"

s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
M2C_UNK func_020cea74();                            /* extern */
M2C_UNK func_020dca50();                            /* extern */
extern M2C_UNK data_0211e400;

void func_020dcacc(void) {
    s32 temp_r4;

    temp_r4 = func_020ce804();
    if (M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 0xC), s32 *, 0x1320) == 0) {
        func_020cea74();
    }
    func_020dca50();
    func_020ce818(temp_r4);
}
