#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02074c3c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    mov ip, #0x0
    strb ip, [r0, #0x0]
    str ip, [r0, #0x10]
    ldr r3, [r1, #0x0]
    ldr r2, [sp, #0x8]
    str r3, [r0, #0x14]
    ldr r3, [r1, #0x4]
    str r3, [r0, #0x18]
    ldr r1, [r1, #0x8]
    str r1, [r0, #0x1c]
    str r2, [r0, #0x20]
    str ip, [r0, #0x24]
    str ip, [r0, #0x28]
    add sp, sp, #0x10
    bx lr
}
// clang-format on
