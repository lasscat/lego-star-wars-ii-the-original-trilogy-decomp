#include "m2c.h"

extern u32 data_020f88c4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02060a78(s32 a0, s32 a1, s32 a2, ...) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov     r9, #0x0
    cmp     r2, #0x0
    ldmleia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
L_02060a88:
    ldrh    r4, [r0, #0x4]
    ldrsh   r8, [r0, #0x2]
    add     r5, r1, r3
    mov     r4, r4, asr #0x4
    mov     r10, r4, lsl #0x1
    ldr     r7, =data_020f88c4
    ldrsh   r6, [r0], #0x6
    add     r7, r7, r10, lsl #0x1
    ldrsh   r7, [r7, #0x2]
    add     r11, r5, r3
    mov     r4, r10, lsl #0x1
    add     r10, r11, r3
    str     r10, [sp, #0x0]
    smull   lr, r10, r7, r6
    adds    lr, lr, #0x800
    adc     r10, r10, #0x0
    mov     ip, lr, lsr #0xc
    orr     ip, ip, r10, lsl #0x14
    strh    ip, [r1, #0x0]
    ldr     r10, =data_020f88c4
    smull   lr, ip, r7, r8
    ldrsh   r4, [r10, r4]
    add     r9, r9, #0x1
    smull   r10, r7, r4, r6
    adds    r10, r10, #0x800
    adc     r6, r7, #0x0
    mov     r7, r10, lsr #0xc
    orr     r7, r7, r6, lsl #0x14
    strh    r7, [r1, r3]
    rsb     r1, r4, #0x0
    smull   r6, r4, r1, r8
    adds    r6, r6, #0x800
    adc     r1, r4, #0x0
    mov     r4, r6, lsr #0xc
    orr     r4, r4, r1, lsl #0x14
    strh    r4, [r5, r3]
    adds    r4, lr, #0x800
    adc     r1, ip, #0x0
    mov     r4, r4, lsr #0xc
    orr     r4, r4, r1, lsl #0x14
    ldr     r1, [sp, #0x0]
    strh    r4, [r11, r3]
    add     r1, r1, r3
    cmp     r9, r2
    blt     L_02060a88
    ldmfd   sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
