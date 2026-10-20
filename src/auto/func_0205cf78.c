#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205cf78(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    stmdb   sp!, {r3, lr}
    ldr     ip, [sp, #0x8]
    cmp     ip, #0x4
    ldreqb  ip, [r0, #0x2a]
    streq   ip, [sp, #0x8]
    ldr     lr, [sp, #0x8]
    mov     ip, #0xa
    mla     r0, lr, ip, r0
    ldrh    ip, [r0, #0x4]
    mov     r0, #0x0
    tst     ip, #0x20
    beq     L_0205cf7834
    ldr     r0, [r1, #0x0]
    sub     r0, r0, #0x1
    cmp     r0, r2
    sublt   r0, r3, #0x1
    str     r0, [r1, #0x0]
    mov     r0, #0x1
    ldmfd   sp!, {r3, pc}
L_0205cf7834:
    tst     ip, #0x10
    ldmeqia sp!, {r3, pc}
    ldr     r0, [r1, #0x0]
    add     r0, r0, #0x1
    cmp     r0, r3
    movne   r2, r0
    str     r2, [r1, #0x0]
    mov     r0, #0x1
    ldmfd   sp!, {r3, pc}
}
// clang-format on
