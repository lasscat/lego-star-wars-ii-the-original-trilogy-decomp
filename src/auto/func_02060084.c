#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02060084(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    stmdb   sp!, {r4, r5, r6, lr}
    add     r5, r0, #0xd4
    add     ip, r0, r1, lsl #0x2
    ldr     lr, [r5, r1, lsl #0x2]
    ldr     r6, [ip, #0xd4]
    add     r4, lr, #0x1
    add     lr, r0, r1, lsl #0x5
    str     r4, [r5, r1, lsl #0x2]
    orr     r2, r2, r3, lsl #0x10
    add     r0, lr, r6, lsl #0x2
    cmp     r3, #0x0
    ldr     r4, [sp, #0x10]
    str     r2, [r0, #0x94]
    sub     r3, r3, #0x1
    ldmeqia sp!, {r4, r5, r6, pc}
L_020600c0:
    add     r4, r4, #0x4
    ldr     r0, [ip, #0xd4]
    ldr     r2, [r4, #-0x4]
    mov     r1, r0
    add     r0, r0, #0x1
    str     r0, [ip, #0xd4]
    add     r0, lr, r1, lsl #0x2
    cmp     r3, #0x0
    str     r2, [r0, #0x94]
    sub     r3, r3, #0x1
    bne     L_020600c0
    ldmfd   sp!, {r4, r5, r6, pc}
}
// clang-format on
