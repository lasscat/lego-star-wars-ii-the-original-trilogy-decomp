#include "m2c.h"

extern void func_0205c69c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02010af0(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r1, [r4, #0x190]
    cmp r1, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    ldrb r0, [r1, #0x2e]
    cmp r0, #0x0
    ldreqb r0, [r1, #0x2f]
    cmpeq r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    ldr r0, [r4, #0x148]
    add r1, sp, #0x0
    cmp r0, #0x0
    ldrne r0, [r0, #0x0]
    add r2, r4, #0x8c
    strne r0, [sp, #0x0]
    moveq r0, #0x0
    streq r0, [sp, #0x0]
    ldr r3, [r1, #0x0]
    ldr r0, [r4, #0x190]
    mov r1, r4
    mov     r3, r3, asr 0xc
    bl      func_0205c69c
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia   sp!, {r3, r4, pc}
    add r0, r4, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x200
    strh r1, [r0, #0xa8]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
