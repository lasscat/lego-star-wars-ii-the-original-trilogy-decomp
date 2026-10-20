#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204d6d4(s32 a0, s32 a1) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     lr, [r0, #0x28]
    ldr     ip, [r0, #0x8]
    ldr     r4, [r1, #0x28]
    ldr     r3, [r1, #0x8]
    add     r5, ip, lr
    sub     r2, r3, r4
    cmp     r5, r2
    sub     r5, ip, lr
    add     r2, r3, r4
    blt     L_0204d708
    cmp     r5, r2
    ble     L_0204d710
L_0204d708:
    mov     r0, #0x0
    ldmfd   sp!, {r3, r4, r5, pc}
L_0204d710:
    ldr     ip, [r0, #0x4]
    ldr     r5, [r1, #0x4]
    ldr     r4, [r0, #0xc]
    ldr     r2, [r0, #0x2c]
    ldr     r3, [r1, #0xc]
    ldr     r0, [r1, #0x2c]
    sub     r1, ip, r5
    add     r5, r2, r0
    sub     ip, r4, r3
    smull   r0, r2, r1, r1
    adds    r4, r0, #0x800
    mov     r0, #0x0
    smull   r1, r3, ip, ip
    adc     lr, r2, r0
    adds    ip, r1, #0x800
    mov     r4, r4, lsr #0xc
    smull   r2, r1, r5, r5
    adc     r3, r3, r0
    adds    r2, r2, #0x800
    mov     ip, ip, lsr #0xc
    orr     r4, r4, lr, lsl #0x14
    orr     ip, ip, r3, lsl #0x14
    adc     r1, r1, r0
    mov     r2, r2, lsr #0xc
    add     r3, r4, ip
    orr     r2, r2, r1, lsl #0x14
    cmp     r3, r2
    movle   r0, #0x1
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
