#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02007eb4(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r3, lr}
    ldr     r3, [r2, #0x8]
    ldr     ip, [r1, #0x8]
    ldr     lr, [r1, #0x0]
    sub     r3, ip, r3
    smull   ip, r1, r3, r3
    ldr     r2, [r2, #0x0]
    ldr     r3, =0x40002b0
    sub     r2, lr, r2
    smlal   ip, r1, r2, r2
    mov     r2, #0x1
    mov     r1, r1, lsl #0x2
    strh    r2, [r3, #0x0]
    mov     r2, ip, lsl #0x2
    str     r2, [r3, #0x8]
    orr     r1, r1, ip, lsr #0x1e
    str     r1, [r3, #0xc]
L_02007ef8:
    ldrh    r1, [r3, #0x0]
    tst     r1, #0x8000
    bne     L_02007ef8
    ldr     r1, =0x40002b4
    ldr     r1, [r1, #0x0]
    add     r1, r1, #0x1
    mov     r1, r1, lsr #0x1
    str     r1, [r0, #0x0]
    ldmfd   sp!, {r3, pc}
}
// clang-format on
