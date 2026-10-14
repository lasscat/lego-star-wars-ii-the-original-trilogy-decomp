#include "m2c.h"

M2C_UNK func_020b8df0();                            /* extern */
s32 func_020ccec8();                                /* extern */
M2C_UNK func_020d5050(u16);                         /* extern */
extern s32 data_02101b74;

s32 func_02052f9c(void) {
    s32 temp_r0;

    func_020b8df0();
    temp_r0       = func_020ccec8();
    data_02101b74 = temp_r0;
    if (temp_r0 == -3) {
        return 0;
    }
    func_020d5050((u16) temp_r0);
    return 1;
}
