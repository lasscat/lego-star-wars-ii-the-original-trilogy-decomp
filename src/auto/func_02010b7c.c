#include "m2c.h"

extern void func_0205c4d4();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02010b7c(s32 a0) {
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldr r2, [r4, #0x190]
    cmp r2, #0x0
    addeq sp, sp, #0x8
    ldmeqia   sp!, {r4, pc}
    ldrb r0, [r2, #0x2e]
    cmp r0, #0x0
    cmpeq r1, #0x0
    ldreqb r0, [r2, #0x2f]
    cmpeq r0, #0x0
    addeq sp, sp, #0x8
    ldmeqia   sp!, {r4, pc}
    ldr r0, [r4, #0x148]
    add r2, sp, #0x4
    cmp r0, #0x0
    ldrne r0, [r0, #0x0]
    strne r0, [sp, #0x4]
    moveq r0, #0x0
    streq r0, [sp, #0x4]
    str r1, [sp, #0x0]
    ldr r3, [r2, #0x0]
    ldr r0, [r4, #0x190]
    mov r1, r4
    add r2, r4, #0x8c
    mov     r3, r3, asr 0xc
    bl      func_0205c4d4
    add r0, r4, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x200
    strh r1, [r0, #0xa8]
    add sp, sp, #0x8
    ldmia   sp!, {r4, pc}
}
// clang-format on
