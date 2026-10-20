#include "m2c.h"

extern void func_0205ccd4(s32, s32);
extern void func_0204a124(s32, s32, s32);
extern s32 func_0205c774(s32, s32, s32, s32);

// clang-format off
asm void func_0205c69c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0x18
    mov r9, r0
    ldrh r0, [r9, #0x2a]
    mov r6, r3
    mov r8, r1
    cmp r6, r0
    subge r6, r0, #0x1
    add r0, r8, #0x2c
    mov r7, r2
    mov r4, #0x0
    bl func_0205ccd4
    ldrb r0, [r9, #0x2f]
    cmp r0, #0x0
    beq L_0205c748
    ldrb r1, [r7, #0x44]
    ldrb r0, [r7, #0x45]
    orrs r0, r1, r0
    ldrne r5, [r8, #0x20]
    cmpne r5, #0x0
    beq L_0205c748
    add r0, sp, #0x0
    add r1, r9, #0x1c
    add r2, r7, #0x30
    bl func_0204a124
    ldr r3, [r8, #0xb8]
    ldr r0, [sp, #0x8]
    ldr r2, [r8, #0xb4]
    add r0, r3, r0
    ldr r1, [sp, #0x4]
    ldr r3, [r8, #0xb0]
    add r4, r2, r1
    ldr r2, [sp, #0x0]
    add r1, sp, #0xc
    add r3, r3, r2
    add r2, r5, #0x4
    cmp r2, r1
    stmneib r5, {r3, r4}
    str r4, [sp, #0x10]
    str r3, [sp, #0xc]
    str r0, [sp, #0x14]
    strne r0, [r5, #0xc]
    mov r4, #0x1
L_0205c748:
    mov r0, r9
    mov r1, r8
    mov r2, r7
    mov r3, r6
    bl func_0205c774
    orrs r0, r4, r0
    movne r0, #0x1
    moveq r0, #0x0
    strh r6, [r9, #0x2c]
    add sp, sp, #0x18
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
