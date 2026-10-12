#include "m2c.h"

void func_02064b10(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg0, s16 *, 4) = (s16) M2C_FIELD(arg1, s16 *, 0);
    M2C_FIELD(arg0, s16 *, 6) = (s16) M2C_FIELD(arg1, s16 *, 2);
    M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg2, s16 *, 0);
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg2, s16 *, 2);
    M2C_FIELD(arg0, s8 *, 0) = 1;
}
