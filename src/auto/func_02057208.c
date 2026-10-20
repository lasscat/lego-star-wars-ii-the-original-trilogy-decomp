#include "m2c.h"

extern void func_020aaeb4();
extern void func_020a1434();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02057208(s32 a0) {
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x8
    ldmfd r1, {r0, r2}
    str r2, [sp, #0x0]
    str r0, [sp, #0x4]
    bl      func_020aaeb4
    add r1, sp, #0x4
    add r2, sp, #0x0
    ldr r1, [r1, #0x0]
    ldr r2, [r2, #0x0]
    bl      func_020a1434
    add sp, sp, #0x8
    ldmia   sp!, {r3, pc}
}
// clang-format on
