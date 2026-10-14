#include "m2c.h"

void func_0205e068(void *arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 4)    = (void *) M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = arg1;
    M2C_FIELD(arg0, u16 *, 0x1E)   = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + 1);
}
