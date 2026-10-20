#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020506a0(s32 a0, s32 a1, s32 a2) {
    stmdb   sp!, {r4, r5, lr}
    sub     sp, sp, #0xc
    ldr     r3, [r2, #0x0]
    cmp     r3, #0x0
    addge   ip, r1, #0x28
    bge     L_020506a030
    ldr     r3, [r1, #0x28]
    add     ip, sp, #0x8
    rsb     r3, r3, #0x0
    str     r3, [sp, #0x8]
L_020506a030:
    ldr     r4, [r2, #0x4]
    ldr     r3, [ip, #0x0]
    cmp     r4, #0x0
    addge   ip, r1, #0x2c
    bge     L_020506a054
    ldr     r4, [r1, #0x2c]
    add     ip, sp, #0x4
    rsb     r4, r4, #0x0
    str     r4, [sp, #0x4]
L_020506a054:
    ldr     r2, [r2, #0x8]
    ldr     r5, [ip, #0x0]
    cmp     r2, #0x0
    addge   lr, r1, #0x30
    bge     L_020506a078
    ldr     r2, [r1, #0x30]
    add     lr, sp, #0x0
    rsb     r2, r2, #0x0
    str     r2, [sp, #0x0]
L_020506a078:
    ldmib   r1, {r2, ip}
    ldr     r4, [r1, #0xc]
    ldr     lr, [lr, #0x0]
    add     r1, r2, r3
    str     r1, [r0, #0x0]
    add     r1, ip, r5
    str     r1, [r0, #0x4]
    add     r1, r4, lr
    str     r1, [r0, #0x8]
    add     sp, sp, #0xc
    ldmfd   sp!, {r4, r5, pc}
}
// clang-format on
