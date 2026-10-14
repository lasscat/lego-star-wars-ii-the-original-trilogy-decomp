#include "m2c.h"

extern void *data_021027f4;

void func_0205aff8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0)   = 0;
    M2C_FIELD(arg0, s32 *, 4)   = 0;
    M2C_FIELD(arg0, void **, 8) = (void *) (arg0 + 4);
    data_021027f4               = arg0;
}
