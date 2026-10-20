#include "m2c.h"

extern void func_01ff97c4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204f9bc(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x10
    ldr r5, [r2, #0x8]
    ldmib r3, {r4, r6}
    ldr lr, [r2, #0x4]
    ldr ip, [r3, #0x0]
    ldr r3, [r2, #0x0]
    sub r4, r4, lr
    sub lr, ip, r3
    sub r5, r6, r5
    ldr ip, [sp, #0x20]
    add r3, sp, #0x4
    str lr, [sp, #0x4]
    str r4, [sp, #0x8]
    str r5, [sp, #0xc]
    str ip, [sp, #0x0]
    bl      func_01ff97c4
    add sp, sp, #0x10
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
