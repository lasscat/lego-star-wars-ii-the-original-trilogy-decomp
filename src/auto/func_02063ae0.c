#include "m2c.h"

extern void func_02063968();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02063ae0(s32 a0) {
    stmdb   sp!, {lr}
    sub sp, sp, #0x14
    mvn r3, #0xff
    sub r2, r3, #0xf00
    strh r2, [sp, #0xe]
    strh r3, [sp, #0xc]
    ldrh r2, [sp, #0xe]
    mov r3, #0x2000
    strh r3, [sp, #0x10]
    ldrh r3, [sp, #0xc]
    strh r2, [sp, #0x0]
    ldrh r2, [sp, #0x10]
    strh r3, [sp, #0x4]
    str r1, [sp, #0x8]
    sub r3, sp, #0x4
    strh r2, [r3, #0x0]
    mov r1, #0x0
    ldr r3, [r3, #0x0]
    mov r2, r1
    bl      func_02063968
    add sp, sp, #0x14
    ldmia   sp!, {pc}
}
// clang-format on
