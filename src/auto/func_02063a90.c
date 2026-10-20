#include "m2c.h"

extern void func_02063968();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02063a90(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0x14
    mov r2, #0x100
    strh r2, [sp, #0xc]
    ldrh ip, [sp, #0xc]
    mov r2, #0x0
    mov r3, #0x2000
    strh r3, [sp, #0x10]
    strh r2, [sp, #0x0]
    strh ip, [sp, #0x4]
    str r1, [sp, #0x8]
    ldrh r3, [sp, #0x10]
    sub r1, sp, #0x4
    strh r2, [sp, #0xe]
    strh r3, [r1, #0x0]
    ldr r3, [r1, #0x0]
    mov r1, r2
    bl      func_02063968
    add sp, sp, #0x14
    ldmia   sp!, {pc}
}
// clang-format on
