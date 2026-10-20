#include "m2c.h"

extern u32 data_020ff380[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208345c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb   sp!, {r3, lr}
    ldr     lr, =data_020ff380
    add     ip, r0, #0x20
    str     lr, [r0, #0x0]
    ldr     lr, [r2, #0x0]
    str     lr, [r0, #0x4]
    ldr     lr, [r2, #0x4]
    str     lr, [r0, #0x8]
    ldr     r2, [r2, #0x8]
    str     r2, [r0, #0xc]
    ldr     r2, [r3, #0x0]
    str     r2, [r0, #0x10]
    ldr     r2, [r3, #0x4]
    str     r2, [r0, #0x14]
    ldr     r2, [r3, #0x8]
    mov     r3, #0xff
    str     r2, [r0, #0x18]
    strb    r1, [r0, #0x1c]
    add     r1, r0, #0x26
    mov     r2, #0x0
L_020834ac:
    strb    r3, [ip, #0x0]
    strb    r2, [ip, #0x1]
    add     ip, ip, #0x2
    cmp     ip, r1
    blo     L_020834ac
    ldmfd   sp!, {r3, pc}
}
// clang-format on
