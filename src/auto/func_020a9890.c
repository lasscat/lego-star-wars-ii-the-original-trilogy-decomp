#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020a9890(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3}
    sub sp, sp, #0x4
    add r1, r0, #0x100
    ldrh r3, [r1, #0xa8]
    ldrh r2, [sp, #0xc]
    strh r3, [sp, #0x0]
    cmp r2, r3
    addeq sp, sp, #0x4
    ldmeqia sp!, {r3}
    addeq sp, sp, #0x10
    bxeq lr
    strh r2, [sp, #0x2]
    ldrh r3, [sp, #0x2]
    mvn r2, #0x0
    strh r3, [r1, #0xa8]
    str r2, [r0, #0x1ac]
    add sp, sp, #0x4
    ldmfd sp!, {r3}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
