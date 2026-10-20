#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020e3fa8(void) {
    add     sp, sp, #0xa4
    ldmfd   sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
