#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void OS_SetProtectionRegion2(u32 a0) {
    mcr     p15, 0, r0, c6, c2, 0
    bx      lr
}
// clang-format on
