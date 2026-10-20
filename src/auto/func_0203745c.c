#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0203745c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb   sp!, {r0, r1, r2, r3}
    cmp     r1, #0x8
    movne   r0, #0x0
    addne   sp, sp, #0x10
    bxne    lr
    ldr     r1, [sp, #0x8]
    strh    r1, [r0, #0xe]
    mov     r0, #0x1
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
