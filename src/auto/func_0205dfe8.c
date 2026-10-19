#include "m2c.h"

void func_0205dfe8(void *arg0) {
    s32 i;

    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x1E) = 0;
    M2C_FIELD(arg0, s8 *, 0x22)  = 0;
    for (i = 0; i < 5; i++) {
        ((s32 *) arg0)[i + 1] = 0;
    }
}
