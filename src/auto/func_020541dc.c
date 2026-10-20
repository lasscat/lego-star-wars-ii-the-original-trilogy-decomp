#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020541dc(s32 a0, s32 a1, s32 a2, s32 a3, ...) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr     r7, [sp, #0x24]
    mov     ip, #0x10
    ldrsh   r5, [r7, #0x2]
    mov     r6, ip, lsl r3
    mul     r8, r5, r6
    ldrb    r4, [sp, #0x21]
    ldrb    lr, [sp, #0x22]
    add     r8, r2, r8, lsl #0x1
    mul     r6, r4, r1
    ldrb    r4, [sp, #0x23]
    add     r6, r0, r6, lsl #0x1
    sub     r0, r1, lr
    ldrb    r5, [sp, #0x20]
    rsb     r2, lr, ip, lsl r3
    ldrsh   r7, [r7, #0x0]
    add     ip, r6, r5, lsl #0x1
    ldr     r5, [sp, #0x28]
    add     r3, r8, r7, lsl #0x1
    cmp     r4, #0x0
    mov     r1, #0x0
    ldmleia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    ldr     r8, [sp, #0x2c]
    mov     r7, r1
L_0205423c:
    mov     r9, r7
    cmp     lr, #0x0
    ble     L_02054264
L_02054248:
    ldrh    r6, [ip], #0x2
    add     r9, r9, #0x1
    cmp     r9, lr
    add     r6, r6, r8, lsl #0xc
    add     r6, r5, r6
    strh    r6, [r3], #0x2
    blt     L_02054248
L_02054264:
    add     r1, r1, #0x1
    cmp     r1, r4
    add     r3, r3, r2, lsl #0x1
    add     ip, ip, r0, lsl #0x1
    blt     L_0205423c
    ldmfd   sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
