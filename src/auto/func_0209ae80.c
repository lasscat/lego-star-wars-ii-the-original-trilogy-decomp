#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0209ae80(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov     r4, r3, asr #0x2
    add     r4, r3, r4, lsr #0x1d
    mov     r3, r2, asr #0x2
    add     r2, r2, r3, lsr #0x1d
    mov     r4, r4, asr #0x3
    mov     r3, r4, lsl #0x10
    cmp     r1, #0x3e8
    mov     r2, r2, lsl #0xd
    mov     r3, r3, asr #0xb
    ldr     r4, [r0, #0xa4]
    add     r2, r3, r2, asr #0x10
    add     r3, r4, r2, lsl #0x1
    ldrhs   r1, =0x3e7
    ldr     r6, =0x66666667
    mov     ip, #0x0
    mov     r4, #0xa
L_0209aec4:
    mov     r5, r1, lsr #0x1f
    smull   lr, r2, r6, r1
    add     r2, r5, r2, asr #0x2
    smull   r2, lr, r4, r2
    rsb     r8, ip, #0x2
    ldr     r7, [r0, #0xa4]
    sub     r2, r1, r2
    add     r7, r7, r2, lsl #0x1
    add     lr, r7, #0x600
    smull   r1, r7, r6, r1
    rsb     r1, ip, #0x22
    ldrh    r9, [lr, #0x0]
    mov     r8, r8, lsl #0x1
    mov     lr, r1, lsl #0x1
    strh    r9, [r3, r8]
    ldr     r1, [r0, #0xa4]
    add     r7, r5, r7, asr #0x2
    add     r1, r1, r2, lsl #0x1
    add     r1, r1, #0x600
    ldrh    r5, [r1, #0x40]
    mov     r1, r7, lsl #0x10
    add     r2, ip, #0x1
    strh    r5, [r3, lr]
    movs    r1, r1, lsr #0x10
    and     ip, r2, #0xff
    bne     L_0209aec4
    ldmfd   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
