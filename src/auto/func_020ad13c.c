#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020ad13c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3}
    sub sp, sp, #0x4
    ldr r3, [r1, #0x154]
    ldr r2, [sp, #0x10]
    str r3, [r0, #0x0]
    ldr r0, [r1, #0x154]
    ldr r3, [r1, #0x158]
    cmp r0, r2
    ldreq r0, [r1, #0x158]
    str r3, [sp, #0x0]
    cmpeq r0, r3
    addeq sp, sp, #0x4
    ldmeqia sp!, {r3}
    addeq sp, sp, #0x10
    bxeq lr
    ldr r2, [sp, #0x10]
    ldr r0, [sp, #0x0]
    str r2, [r1, #0x154]
    str r0, [r1, #0x158]
    mvn r0, #0x0
    str r0, [r1, #0x160]
    add sp, sp, #0x4
    ldmfd sp!, {r3}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
