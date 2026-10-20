#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02064998(s32 a0, s32 a1, s32 a2, s32 a3, ...) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    cmp     r3, #0x0
    ldr     r0, [sp, #0x28]
    ldrsh   r1, [sp, #0x1e]
    mov     r5, #0x0
    beq     L_02064a18
    ldrh    r7, [sp, #0x1c]
    mov     r1, r1, lsl #0x10
    mov     r6, r1, lsr #0x10
L_020649c0:
    ldrh    r1, [r2, #0x0]
    ldrh    r4, [r2, #0x6]
    ldrh    lr, [r2, #0x4]
    cmp     r7, r1
    ldrh    ip, [r2, #0x2]
    blo     L_02064a08
    add     r1, r1, lr
    cmp     r7, r1
    bge     L_02064a08
    cmp     r6, ip
    blo     L_02064a08
    add     r1, ip, r4
    cmp     r6, r1
    strlt   r5, [r0, #0x0]
    movlt   r0, #0x1
    ldmltia sp!, {r3, r4, r5, r6, r7, lr}
    addlt   sp, sp, #0x10
    bxlt    lr
L_02064a08:
    subs    r3, r3, #0x1
    add     r5, r5, #0x1
    add     r2, r2, #0x8
    bne     L_020649c0
L_02064a18:
    mvn     r1, #0x0
    str     r1, [r0, #0x0]
    mov     r0, #0x0
    ldmfd   sp!, {r3, r4, r5, r6, r7, lr}
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
