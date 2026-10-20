#include "m2c.h"

extern void func_0205c8b0();
extern void func_0205c37c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02010a24(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x8
    mov r5, r0
    ldr r0, [r5, #0x190]
    mov r4, r1
    ldrh r1, [r0, #0x28]
    cmp r4, r1
    addeq sp, sp, #0x8
    ldmeqia   sp!, {r3, r4, r5, pc}
    mov r1, r5
    bl      func_0205c8b0
    ldr r0, [r5, #0x148]
    add r1, sp, #0x4
    cmp r0, #0x0
    ldrne r0, [r0, #0x0]
    mov r2, r4
    strne r0, [sp, #0x4]
    moveq r0, #0x0
    streq r0, [sp, #0x4]
    ldr r0, [r1, #0x0]
    mov r1, r5
    mov     r0, r0, asr 0xc
    str r0, [sp, #0x0]
    ldr r0, [r5, #0x190]
    add r3, r5, #0x8c
    bl      func_0205c37c
    add r0, r5, #0x100
    ldrh r1, [r0, #0xa8]
    orr r1, r1, #0x200
    strh r1, [r0, #0xa8]
    add sp, sp, #0x8
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
