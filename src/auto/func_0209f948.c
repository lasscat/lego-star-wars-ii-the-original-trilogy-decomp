#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0209f948(s32 a0, ...) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    ldr     r2, [sp, #0xc]
    ldr     r1, [r0, #0x74]
    str     r2, [r1, #0x0]
    ldr     r1, [r0, #0xa0]
    cmp     r1, #0x0
    ldmeqia sp!, {r3, lr}
    addeq   sp, sp, #0x10
    bxeq    lr
    mov     r2, #0x0
    strb    r2, [r0, #0xb1]
    mov     r1, #0x6
    ldr     r3, [r0, #0x74]
    smulbb  r1, r2, r1
    ldr     r2, [r0, #0xa0]
    ldr     r3, [r3, #0x0]
    ldrh    r1, [r2, r1]
    mov     lr, r3, asr #0xc
    cmp     r1, r3, asr #0xc
    ldmhsia sp!, {r3, lr}
    addhs   sp, sp, #0x10
    bxhs    lr
    mov     r1, #0x6
L_0209f9a8:
    ldrb    r2, [r0, #0xb1]
    add     ip, r2, #0x1
    and     r2, ip, #0xff
    mul     r3, r2, r1
    strb    ip, [r0, #0xb1]
    ldr     r2, [r0, #0xa0]
    ldrh    r2, [r2, r3]
    cmp     lr, r2
    bhi     L_0209f9a8
    ldmfd   sp!, {r3, lr}
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
