#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020be664(s32 a0, s32 a1) {
    stmdb   sp!, {r3, lr}
    sub     sp, sp, #0x20
    ldr     r3, [r1, #0xc]
    ldr     lr, [r1, #0x4]
    ldr     ip, [r1, #0x8]
    ldr     r2, [r1, #0x10]
    cmp     r3, #0x0
    str     lr, [sp, #0x1c]
    str     ip, [sp, #0x18]
    str     r3, [sp, #0x14]
    str     r2, [sp, #0x10]
    cmpeq   r2, #0x0
    beq     L_020be6b8
    ldr     r3, [sp, #0x14]
    ldr     ip, [sp, #0x10]
    str     r3, [r0, #0x8]
    str     ip, [r0, #0xc]
    mov     r2, #0x1
    str     ip, [sp, #0x8]
    str     r3, [sp, #0xc]
    b       L_020be6cc
L_020be6b8:
    str     lr, [r0, #0x8]
    str     ip, [r0, #0xc]
    mov     r2, #0x0
    str     ip, [sp, #0x0]
    str     lr, [sp, #0x4]
L_020be6cc:
    str     r2, [r0, #0x10]
    add     r0, r1, #0x14
    add     sp, sp, #0x20
    ldmfd   sp!, {r3, pc}
}
// clang-format on
