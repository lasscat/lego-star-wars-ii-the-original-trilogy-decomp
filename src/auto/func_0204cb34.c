#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0204cb34(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    ldr ip, [r1, #0x0]
    ldr r3, [sp, #0xc]
    str ip, [r0, #0x0]
    ldr ip, [r1, #0x4]
    str ip, [r0, #0x4]
    ldr r1, [r1, #0x8]
    str r1, [r0, #0x8]
    str r3, [r0, r2, lsl #0x2]
    add sp, sp, #0x10
    bx lr
}
// clang-format on
