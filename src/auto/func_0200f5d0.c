#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0200f5d0(s32 a0, s32 a1, ...) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, lr}
    ldr     r5, =0x0
    ldr     r2, [sp, #0x18]
    mov     ip, r5
    ldr     lr, [r0, #0x0]
    ldr     r4, [r1, #0x0]
    sub     lr, lr, r4
    ldr     ip, [r0, #0x4]
    ldr     r4, [r1, #0x4]
    sub     ip, ip, r4
    ldr     r0, [r0, #0x8]
    ldr     r4, [r1, #0x8]
    sub     r0, r0, r4
    smull   lr, r4, lr, lr
    smlal   lr, r4, ip, ip
    smlal   lr, r4, r0, r0
    smull   ip, r0, r2, r2
    subs    ip, lr, ip
    sbc     ip, r4, r0
    mov     ip, ip, lsr #0x1f
    mov     lr, lr, lsr #0xc
    orr     lr, lr, r4, lsl #0x14
    str     lr, [r3, #0x0]
    cmp     ip, #0x0
    beq     L_0200f63c
    mov     r5, #0x1
L_0200f63c:
    mov     r0, r5
    ldmfd   sp!, {r3, r4, r5, lr}
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
