#include "m2c.h"

extern void func_020985d8();
extern void func_02018210();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02032a78(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x18
    mov r4, r0
    ldr lr, [r4, #0x4]
    ldr r2, [r4, #0x10]
    ldr r0, [lr, #0xb8]
    ldr r1, [r2, #0xb8]
    ldr ip, [r2, #0xb4]
    sub r1, r1, r0
    ldr r3, [lr, #0xb4]
    ldr r2, [r2, #0xb0]
    ldr r0, [lr, #0xb0]
    sub r3, ip, r3
    sub r0, r2, r0
    str r0, [sp, #0xc]
    str r3, [sp, #0x10]
    str r1, [sp, #0x14]
    str r1, [sp, #0x8]
    str r0, [sp, #0x4]
    bl      func_020985d8
    strh r0, [sp, #0x0]
    ldrh r1, [sp, #0x0]
    ldr r0, [r4, #0x4]
    sub r3, sp, #0x4
    strh r1, [r3, #0x0]
    ldrh r2, [r4, #0x14]
    ldr r1, [r3, #0x0]
    strh r2, [r3, #0x0]
    ldr r2, [r3, #0x0]
    bl      func_02018210
    add sp, sp, #0x18
    ldmia   sp!, {r4, pc}
}
// clang-format on
