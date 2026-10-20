#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0204f4c8(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    ldr     ip, [r1, #0x30]
    ldmib   r2, {r3, r4}
    ldr     lr, [r2, #0x0]
    smull   r5, r2, r4, ip
    adds    r6, r5, #0x800
    smull   r4, r5, r3, ip
    adc     r2, r2, #0x0
    adds    r7, r4, #0x800
    smull   r4, ip, lr, ip
    mov     r3, r6, lsr #0xc
    adc     r6, r5, #0x0
    adds    lr, r4, #0x800
    adc     r4, ip, #0x0
    mov     r5, lr, lsr #0xc
    mov     r7, r7, lsr #0xc
    orr     r3, r3, r2, lsl #0x14
    ldr     ip, [r1, #0x4]
    orr     r5, r5, r4, lsl #0x14
    ldr     lr, [r1, #0xc]
    ldr     r2, [r1, #0x8]
    add     r1, ip, r5
    orr     r7, r7, r6, lsl #0x14
    str     r1, [r0, #0x0]
    add     r1, r2, r7
    str     r1, [r0, #0x4]
    add     r1, lr, r3
    str     r1, [r0, #0x8]
    ldmfd   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
