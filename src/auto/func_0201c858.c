#include "m2c.h"

void func_0201c858(u16 *arg0, s32 arg1, u16 arg2) {
    u16 *temp_ip;

    temp_ip = arg0 + arg1;
    if (arg2 == M2C_FIELD(temp_ip, u16 *, 2)) {
        return;
    }
    M2C_FIELD(temp_ip, u16 *, 2) = arg2;
    if (arg2 == 0xFFFF) {
        *arg0 &= ~(1 << arg1);
        return;
    }
    *arg0 |= 1 << arg1;
}
