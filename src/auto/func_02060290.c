#include "m2c.h"

extern void func_02060710(void *p);

void func_02060290(void *p, s32 v, ...) {
    s32 val                   = *(volatile s32 *) &v;
    M2C_FIELD(p, s32 *, 0x1c) = val;
    func_02060710(p);
}
