#include "m2c.h"

extern void func_020aaeb4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020578f4(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x20
    ldmfd r1, {r0, r2, r3, ip}
    ldrb r4, [r1, #0x10]
    str r0, [sp, #0xc]
    str ip, [sp, #0x10]
    str ip, [sp, #0x0]
    str r3, [sp, #0x14]
    str r3, [sp, #0x4]
    str r2, [sp, #0x18]
    str r2, [sp, #0x8]
    str r0, [sp, #0x1c]
    bl      func_020aaeb4
    ldr r2, [sp, #0xc]
    strb r4, [r0, #0x378]
    str r2, [r0, #0x380]
    ldr r1, [sp, #0x8]
    ldr r2, [sp, #0x4]
    str r1, [r0, #0x384]
    ldr r1, [sp, #0x0]
    str r2, [r0, #0x388]
    str r1, [r0, #0x38c]
    add sp, sp, #0x20
    ldmia   sp!, {r4, pc}
}
// clang-format on
