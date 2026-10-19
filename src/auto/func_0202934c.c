#include "m2c.h"
void func_0202934c(void *arg0, void *arg1) {
    s32 arr[3];
    void *p;
    if (arg1 != NULL) {
        p = (u8 *) arg1 + 0xB0;
    } else {
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        p      = arr;
    }
    M2C_FIELD(arg0, s32 *, 0) = M2C_FIELD(p, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 4) = M2C_FIELD(p, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(p, s32 *, 8);
}
