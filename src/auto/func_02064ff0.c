#include "m2c.h"

s32 func_02065078(void *, s32, s32, s32, s32);      /* extern */
s32 func_020c3c48(void *);                          /* extern */
s32 func_020c3c54(void *);                          /* extern */
M2C_UNK func_020c3c60(void *, s32, s32);            /* extern */
s32 func_020c3d2c(void *);                          /* extern */
M2C_UNK func_020c3d38(void *, s32);                 /* extern */

s32 func_02064ff0(void *arg0, void *arg1) {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_ip;

    if (arg1 != NULL) {
        temp_r4 = func_020c3c48(arg1);
        temp_r5 = func_020c3c54(arg1);
        temp_r3 = func_020c3d2c(arg1);
        if (M2C_FIELD(arg1, u16 *, 0x20) & 0x8000) {
            var_ip = 1;
        } else {
            var_ip = 0;
        }
        if (func_02065078(arg0, temp_r4, temp_r5, temp_r3, var_ip) != 0) {
            func_020c3c60(arg1, M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4));
            func_020c3d38(arg1, M2C_FIELD(arg0, s32 *, 8));
        }
        return 1;
    }
    return 0;
}
