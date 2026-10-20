#include "m2c.h"

extern void func_02098504();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02018210(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldrh r1, [r4, #0xca]
    ldrh r0, [sp, #0x14]
    sub r3, sp, #0x4
    strh r1, [sp, #0x2]
    strh r0, [r3, #0x0]
    ldrh r2, [sp, #0x18]
    ldr r1, [r3, #0x0]
    add r0, sp, #0x2
    strh r2, [r3, #0x0]
    ldr r2, [r3, #0x0]
    bl      func_02098504
    ldrh r2, [sp, #0x2]
    ldrh r1, [r4, #0xca]
    strh r2, [sp, #0x0]
    cmp r1, r2
    strneh r2, [r4, #0xca]
    movne r1, #0x1
    strneb r1, [r4, #0xd0]
    add sp, sp, #0x4
    ldmfd   sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
