#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020838b8(s32 a0, s32 a1) {
    stmdb   sp!, {r4, r5, r6, lr}
    ldrb    r2, [r1, #0x89]
    cmp     r2, #0x0
    beq     L_02083938
    ldrb    r4, [r1, #0x88]
    mov     r3, #0x0
L_020838d0:
    add     r2, r0, r3
    ldrb    r2, [r2, #0x1d]
    cmp     r4, r2
    moveq   r0, #0x1
    ldmeqia sp!, {r4, r5, r6, pc}
    add     r3, r3, #0x1
    cmp     r3, #0x3
    blt     L_020838d0
    ldrb    r6, [r1, #0x88]
    mov     r4, #0x0
    mov     r2, #0x1
    mov     lr, r4
L_02083900:
    add     ip, r0, r4, lsl #0x1
    ldrb    r3, [ip, #0x20]
    mov     r5, lr
    cmp     r3, r6
    ldreqb  ip, [ip, #0x21]
    ldreqb  r3, [r1, #0x89]
    cmpeq   ip, r3
    moveq   r5, r2
    cmp     r5, #0x0
    movne   r0, #0x1
    ldmneia sp!, {r4, r5, r6, pc}
    add     r4, r4, #0x1
    cmp     r4, #0x3
    blt     L_02083900
L_02083938:
    mov     r0, #0x0
    ldmfd   sp!, {r4, r5, r6, pc}
}
// clang-format on
