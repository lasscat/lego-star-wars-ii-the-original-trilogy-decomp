#include "m2c.h"
void func_0209d08c(s32 a0, u32 a1, s32 a2) {
    if (*(s8 *) (a0 + 0xf0) == -1) {
        *(s8 *) (a0 + 0xf0) = a2;
    }
    *(s32 *) (a0 + 0xbc + a2 * 4) += 1;
    *(s32 *) (a0 + 0xcc + a1 * 4) += 1;
}
