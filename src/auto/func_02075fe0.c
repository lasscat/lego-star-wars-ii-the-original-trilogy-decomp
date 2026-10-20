#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02075fe0(s32 a0) {
    mov     r3, #0x0
L_02075fe4:
    add     r1, r0, r3, lsl #0x2
    ldr     r2, [r1, #0xc]
    add     r3, r3, #0x1
    ldr     r1, [r2, #0x8]
    cmp     r3, #0x4
    bic     r1, r1, #0x1
    str     r1, [r2, #0x8]
    blt     L_02075fe4
    bx      lr
}
// clang-format on
