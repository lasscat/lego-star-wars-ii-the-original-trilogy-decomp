#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02074c7c(s32 a0, s32 a1, s32 a2) {
    cmp     r2, #0x0
    add     r2, r0, #0x2
    ldrneb  r0, [r2, r1, lsl #0x1]
    bicne   r0, r0, #0x40
    ldreqb  r0, [r2, r1, lsl #0x1]
    orreq   r0, r0, #0x40
    strb    r0, [r2, r1, lsl #0x1]
    bx      lr
}
// clang-format on
