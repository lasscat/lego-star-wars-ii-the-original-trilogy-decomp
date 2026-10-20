#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02037408(s32 arg0) {
    stmdb sp!, {r3}
    sub     sp, sp, #0xc
    mov     r3, #0x0
    str     r3, [sp, #0x0]
    str     r3, [sp, #0x4]
    str     r3, [sp, #0x8]
    ldr     r0, [r0, #0x4]
    add     r2, sp, #0x0
    add     r1, r0, #0x60
    cmp     r1, r2
    addeq   sp, sp, #0xc
    ldmeqfd sp!, {r3}
    bxeq    lr
    str     r3, [r1, #0x0]
    ldr     r0, [r2, #0x4]
    str     r0, [r1, #0x4]
    ldr     r0, [r2, #0x8]
    str     r0, [r1, #0x8]
    add     sp, sp, #0xc
    ldmfd   sp!, {r3}
    bx      lr
}
// clang-format on
