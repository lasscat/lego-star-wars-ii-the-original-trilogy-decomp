#include "m2c.h"

extern void func_02074c7c(u8 *a0, s32 a1, s32 a2);

void func_02075524(u8 ***a0, s32 a1, s32 a2, s32 a3) {
    func_02074c7c((*a0)[a1], a2, a3);
}
