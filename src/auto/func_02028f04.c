#include "m2c.h"

extern void func_0200c9e4();
extern void func_0200c7dc();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02028f04(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x1c
    mov r1, #0x1000
    mov r4, r0
    str r1, [sp, #0x10]
    str r1, [sp, #0x14]
    str r1, [sp, #0x18]
    add r2, sp, #0x10
    ldmfd r4, {r0, r1}
    bl      func_0200c9e4
    mov r2, #0x0
    mov lr, r2
    mov ip, r2
    ldr r3, [r4, #0x0]
    ldr r1, [r4, #0x4]
    mov r0, #0x28
    mla r0, r1, r0, r3
    add r0, r0, #0x100
    strh r2, [r0, #0xc8]
    strh lr, [r0, #0xca]
    strh ip, [r0, #0xcc]
    mov r1, #0x1
    strh r1, [r0, #0xce]
    mov r3, #0x38
    ldmfd r4, {r0, r1}
    mla r3, r1, r3, r0
    ldrb r3, [r3, #0x3cc]
    strh r2, [sp, #0x8]
    strh r2, [sp, #0xa]
    strh r2, [sp, #0x6]
    strh r2, [sp, #0x0]
    strh lr, [sp, #0x2]
    strh ip, [sp, #0x4]
    cmp r3, #0x0
    beq      L_02028f94
    bl      func_0200c7dc
    L_02028f94:
    ldr r1, [r4, #0x14]
    cmp r1, #0x0
    ldrne r0, [r1, #0x8]
    orrne r0, r0, #0x2
    strne r0, [r1, #0x8]
    add sp, sp, #0x1c
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
