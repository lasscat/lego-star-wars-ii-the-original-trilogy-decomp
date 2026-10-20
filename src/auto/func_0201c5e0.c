#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0201c5e0(s32 a0, s32 a1, ...) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    ldr     r4, [r1, #0x4c]
    ldr     lr, [r0, #0x8]
    ldr     ip, [r0, #0x10]
    ldr     r3, [r1, #0x50]
    ldr     r2, [r0, #0xc]
    ldr     r1, [r0, #0x14]
    ldr     r0, [sp, #0x10]
    add     lr, r4, lr
    cmp     r0, lr
    add     ip, r4, ip
    add     r2, r3, r2
    add     r1, r3, r1
    blt     L_0201c644
    cmp     r0, ip
    bgt     L_0201c644
    ldr     r0, [sp, #0x14]
    cmp     r0, r2
    blt     L_0201c644
    cmp     r0, r1
    movle   r0, #0x1
    ldmleia sp!, {r4, lr}
    addle   sp, sp, #0x10
    bxle    lr
L_0201c644:
    mov     r0, #0x0
    ldmfd   sp!, {r4, lr}
    add     sp, sp, #0x10
    bx      lr
}
// clang-format on
