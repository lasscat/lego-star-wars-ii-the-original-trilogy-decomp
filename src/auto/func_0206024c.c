#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0206024c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    ldr ip, [sp, #0x4]
    ldr r2, [r0, #0x8]
    ldr r1, [r0, #0x10]
    sub r2, ip, r2
    add r1, r1, r2
    str r1, [r0, #0x10]
    ldr r3, [sp, #0x8]
    ldr r2, [r0, #0xc]
    ldr r1, [r0, #0x14]
    sub r2, r3, r2
    add r1, r1, r2
    str r1, [r0, #0x14]
    str ip, [r0, #0x8]
    str r3, [r0, #0xc]
    add sp, sp, #0x10
    bx lr
}
// clang-format on
