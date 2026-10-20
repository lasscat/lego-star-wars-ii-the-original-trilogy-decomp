#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200c868(s32 a0, s32 a1) {
    mov     r2, #0x38
    mul     r3, r1, r2
    add     r1, r0, r3
    mov     r2, #0x1
    strb    r2, [r1, #0x3cd]
    strb    r2, [r1, #0x3cc]
    add     r1, r0, #0x3d0
    ldrsb   r0, [r1, r3]
    add     r0, r0, #0x1
    strb    r0, [r1, r3]
    bx      lr
}
// clang-format on
