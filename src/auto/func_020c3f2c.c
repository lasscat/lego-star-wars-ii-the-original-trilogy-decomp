#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020c3f2c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb   sp!, {r4, r5, r6, lr}
    ldrh    r5, [r1, #0x0]
    ldr     r2, [r2, #0x2c]
    ldrh    r4, [r3, #0x2]
    mov     ip, r2, lsl #0x10
    add     r2, r0, r5
    tst     r4, #0x1
    mov     r6, ip, lsr #0x10
    ldrh    r5, [r3, #0x0]
    bne     L_020c3f64
    mov     r3, r5, lsl #0xf
    mov     ip, r6, lsl #0xf
    mov     r5, r3, lsr #0x10
    mov     r6, ip, lsr #0x10
L_020c3f64:
    ldrb    r4, [r1, #0x2]
    mov     r3, #0x0
    cmp     r4, #0x0
    bls     L_020c3fb4
    add     r4, r5, r6
    mov     ip, r4, lsl #0x10
    add     r6, r0, #0x4
    mov     r4, ip, lsr #0x10
L_020c3f84:
    ldrh    r5, [r0, #0xa]
    ldrb    ip, [r2, r3]
    add     r3, r3, #0x1
    ldrh    lr, [r6, r5]
    add     r5, r6, r5
    mla     ip, lr, ip, r5
    ldr     ip, [ip, #0x4]
    add     ip, r0, ip
    strh    r4, [ip, #0x1c]
    ldrb    ip, [r1, #0x2]
    cmp     r3, ip
    blo     L_020c3f84
L_020c3fb4:
    ldrb    r0, [r1, #0x3]
    orr     r0, r0, #0x1
    strb    r0, [r1, #0x3]
    ldmfd   sp!, {r4, r5, r6, pc}
}
// clang-format on
