#include "m2c.h"

extern void func_02010384(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200b10c(s32 a0, s32 a1) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, lr}
    ldr r1, [r0, #0x148]
    add r3, sp, #0x0
    cmp r1, #0x0
    ldrne r1, [r1, #0x0]
    strne r1, [sp, #0x0]
    moveq r1, #0x0
    streq r1, [sp, #0x0]
    add r1, r0, #0x100
    ldrh r2, [r1, #0xbc]
    ldr r1, [r3, #0x0]
    mov r1, r1, lsl #0x4
    sub r2, r2, #0x1
    cmp r2, r1, lsr #0x10
    bgt L_0200b15c
    ldr r1, [r0, #0x8]
    orr r1, r1, #0x2
    bic r1, r1, #0x1
    str r1, [r0, #0x8]
L_0200b15c:
    add r1, sp, #0xc
    ldr r1, [r1, #0x0]
    bl func_02010384
    ldmia sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
