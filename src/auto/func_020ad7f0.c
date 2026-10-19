#include "m2c.h"

M2C_UNK func_020cdd40(s32, s32);                    /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
M2C_UNK func_020ad528();                            /* extern */
s32 func_020d7dac(void *, s32, void *);             /* extern */
extern M2C_UNK data_020fffbc;
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b520;
extern M2C_UNK data_0210b720;

s32 func_020ad7f0(s32 arg0, M2C_UNK arg1) {
    s32 temp_r0;

    func_020cdd40(arg1, M2C_FIELD(&data_0210b320, s32 *, 0x3C));
    temp_r0 = func_020d7dac(&data_0210b720, arg1, &data_0210b520);
    if (temp_r0 == 3) {
        func_020ad8b4();
        return 0;
    }
    if (temp_r0 == 7) {
        return 1;
    }
    if (temp_r0 == 5) {
        func_020ad528(&data_020fffbc);
        func_020ad8b4(temp_r0);
        return 0;
    }
    if (temp_r0 == 0) {
        return 1;
    }
    func_020ad8b4();
    return 0;
}
