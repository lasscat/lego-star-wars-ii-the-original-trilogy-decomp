#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0202d884(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r3, [r2, #0x4]
    ldmfd   r1, {r5, ip}
    sub     r3, ip, r3
    smull   lr, ip, r3, r3
    ldr     r4, [r2, #0x0]
    ldr     r3, [r1, #0x8]
    sub     r4, r5, r4
    ldr     r1, [r2, #0x8]
    smlal   lr, ip, r4, r4
    sub     r1, r3, r1
    smlal   lr, ip, r1, r1
    mov     r1, ip, lsl #0x2
    ldr     r3, =0x40002b0
    mov     r2, #0x1
    strh    r2, [r3, #0x0]
    mov     r2, lr, lsl #0x2
    str     r2, [r3, #0x8]
    orr     r1, r1, lr, lsr #0x1e
    str     r1, [r3, #0xc]
L_0202d8d4:
    ldrh    r1, [r3, #0x0]
    tst     r1, #0x8000
    bne     L_0202d8d4
    ldr     r1, =0x40002b4
    ldr     r1, [r1, #0x0]
    add     r1, r1, #0x1
    mov     r1, r1, lsr #0x1
    str     r1, [r0, #0x0]
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
