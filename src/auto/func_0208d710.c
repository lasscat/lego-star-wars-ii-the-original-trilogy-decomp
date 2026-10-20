#include "m2c.h"

extern u32 data_020ff4dc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208d710(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r4, #0x0
    ldr     ip, =data_020ff4dc
    mov     r5, r4
    mov     r3, #0x1
    mov     lr, r4
L_0208d728:
    ldr     r1, [ip, r5, lsl #0x2]
    mov     r6, lr
    ldrh    r2, [r1, #0x0]
    cmp     r2, #0xfa
    beq     L_0208d76c
L_0208d73c:
    mov     r2, r6, lsl #0x1
    ldrh    r2, [r1, r2]
    cmp     r0, r2
    orreq   r4, r4, r3, lsl r5
    beq     L_0208d76c
    add     r2, r6, #0x1
    mov     r2, r2, lsl #0x10
    mov     r6, r2, lsr #0x10
    mov     r2, r6, lsl #0x1
    ldrh    r2, [r1, r2]
    cmp     r2, #0xfa
    bne     L_0208d73c
L_0208d76c:
    add     r1, r5, #0x1
    and     r5, r1, #0xff
    cmp     r5, #0x7
    blo     L_0208d728
    mov     r0, r4
    ldmfd   sp!, {r4, r5, r6, pc}
}
// clang-format on
