#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02037054(s32 a0) {
    stmdb   sp!, {r3}
    sub     sp, sp, #0x4
    ldr     r1, [r0, #0x4]
    ldr     r0, [r1, #0x148]
    ldr     r2, [r1, #0x174]
    cmp     r0, #0x0
    ldrne   r0, [r0, #0x0]
    add     r1, sp, #0x0
    strne   r0, [sp, #0x0]
    moveq   r0, #0x0
    streq   r0, [sp, #0x0]
    ldr     r0, [r1, #0x0]
    cmp     r2, #0x0
    mov     r1, r0, asr #0xc
    beq     L_020370c4
    ldrh    r0, [r2, #0x0]
    cmp     r1, r0
    blt     L_020370c4
L_0203709c:
    ldrh    r0, [r2, #0x2]
    cmp     r0, #0x6
    cmpne   r0, #0x2
    addeq   sp, sp, #0x4
    moveq   r0, #0x1
    ldmeqfd sp!, {r3}
    bxeq    lr
    ldrh    r0, [r2, #0x6]!
    cmp     r1, r0
    bge     L_0203709c
L_020370c4:
    mov     r0, #0x0
    add     sp, sp, #0x4
    ldmfd   sp!, {r3}
    bx      lr
}
// clang-format on
