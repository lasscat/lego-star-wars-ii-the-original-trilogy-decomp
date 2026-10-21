#include "m2c.h"

s32 func_0201aaec(void);                                /* extern */
void func_02017e8c(void *obj, void *out);               /* extern */

void *func_02055530(void *arg0, s32 arg1, void *arg2) {
    s32 arr[6];
    s32 *p;
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0) = arg1;
    p                         = arr;
    do {
        *p++ = 0;
    } while (p < arr + 6);
    func_02017e8c(arg2, arr);
    temp_r0                      = arr[0] >> (func_0201aaec() + 5);
    M2C_FIELD(arg0, s32 *, 0xC)  = temp_r0;
    M2C_FIELD(arg0, s32 *, 4)    = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x10) = arr[1] >> (func_0201aaec() + 5);
    M2C_FIELD(arg0, s32 *, 8)    = arr[4] >> (func_0201aaec() + 5);
    M2C_FIELD(arg0, s32 *, 0x14) = arr[5] >> (func_0201aaec() + 5);
    return arg0;
}
