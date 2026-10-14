#include "m2c.h"

void func_02045888(void *arg0) {
    void *temp_r0;

    temp_r0                          = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r0, u16 *, 0x1A8) = (u16) (M2C_FIELD(temp_r0, u16 *, 0x1A8) & ~0x100);
}
