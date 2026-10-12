#include "m2c.h"

M2C_UNK func_020ad7a4();                     /* extern */
M2C_UNK func_020ad8b4();                     /* extern */
s32 func_020aeed0();                         /* extern */
extern M2C_UNK data_0210b320;

s32 func_020adaf0(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0210b320, s16 *, 2) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 0xC) = 0x65;
    func_020ad7a4(3);
    temp_r0 = func_020aeed0(1);
    if (temp_r0 == 0x18) {
        func_020ad8b4(0x18);
        func_020ad7a4(9);
        return 0;
    }
    if (temp_r0 == 2) {
        return 1;
    }
    func_020ad8b4();
    func_020ad7a4(9);
    return 0;
}
