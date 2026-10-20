#include "m2c.h"

extern void func_02054c80();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208830c(s32 a0) {
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x28
    str r1, [r0, #0x0]
    mov ip, #0x0
    strh r2, [r0, #0x4]
    strh ip, [sp, #0x1c]
    strh ip, [sp, #0x1e]
    stmea sp, {r2, ip}
    str ip, [sp, #0x8]
    mov r2, #0x100
    str r2, [sp, #0xc]
    add r0, sp, #0x1c
    str r0, [sp, #0x10]
    strb ip, [sp, #0x14]
    strb ip, [sp, #0x15]
    strb ip, [sp, #0x16]
    ldr     r2, =0x593
    add r0, sp, #0x20
    mov r3, #0x2
    strb ip, [sp, #0x18]
    strb ip, [sp, #0x19]
    strb ip, [sp, #0x1a]
    strb ip, [sp, #0x1b]
    strb ip, [sp, #0x17]
    bl      func_02054c80
    add sp, sp, #0x28
    ldmia   sp!, {r3, pc}
}
// clang-format on
