#include "m2c.h"

s32 func_02075bc0(void *arg0, void *arg1) {
    s32 temp_r0;
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg1, s32 *, 4);
    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r0 < temp_r1) {
        return -1;
    }
    if (temp_r0 > temp_r1) {
        return 1;
    }
    return 0;
}
