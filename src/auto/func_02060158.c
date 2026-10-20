#include "m2c.h"

extern void func_02060084();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02060158(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    add r3, sp, #0x14
    bic r3, r3, #0x3
    add r3, r3, #0x4
    str r3, [sp, #0x0]
    ldr r3, [sp, #0x14]
    bl      func_02060084
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
