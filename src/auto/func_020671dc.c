#include "m2c.h"

void func_020676cc(void);
void func_020e4600(s32, s32, s32, s32);
void func_02067710(s32, s32, s32, s32, s32);

// clang-format off
asm void func_020671dc(s32 *arg0, s32 *arg1, s32 *arg2) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x8
    mov r8, r0
    mov r7, r1
    ldrh r1, [r8, #0x18]
    mov r4, r2
    cmp r1, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
    ldr r0, [r7, #0xc]
    cmp r0, #0x0
    beq L_02067224
    ldr r2, =func_020676cc
    mov r3, #0x0
    str r2, [sp, #0x0]
    mov r2, #0x8
    str r3, [sp, #0x4]
    bl func_020e4600
L_02067224:
    str r0, [r8, #0x4]
    ldrh r0, [r8, #0x18]
    ldr r1, [r7, #0xc]
    add r4, r4, #0x10
    mov r0, r0, lsl #0x3
    add r0, r0, #0x8
    add r0, r1, r0
    str r0, [r7, #0xc]
    ldrh r0, [r8, #0x18]
    mov r5, #0x0
    cmp r0, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r4, r5, r6, r7, r8, pc}
    mov r6, r5
L_0206725c:
    ldrb r0, [r8, #0x22]
    mov r1, r7
    mov r2, r5
    str r0, [sp, #0x0]
    ldr r0, [r8, #0x4]
    mov r3, r4
    add r0, r0, r6
    bl func_02067710
    ldrh r1, [r4, #0x0]
    ldrh r0, [r8, #0x18]
    add r5, r5, #0x1
    add r4, r4, r1
    cmp r5, r0
    add r6, r6, #0x8
    blo L_0206725c
    add sp, sp, #0x8
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
}
// clang-format on
