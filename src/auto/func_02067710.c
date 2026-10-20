#include "m2c.h"

void func_020676e4(s32, s32);
void func_020677f0(void);
void func_020e4600(s32, s32, s32, s32);

// clang-format off
asm void func_02067710(s32 *arg0, s32 *arg1, s32 arg2, s32 *arg3, ...) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x8
    mov r5, r3
    ldrb r4, [r5, #0x3]
    mov r7, r0
    ldr r3, [sp, #0x20]
    strb r4, [r7, #0x5]
    strb r2, [r7, #0x4]
    strb r3, [r7, #0x6]
    ldrb r2, [r7, #0x5]
    mov r6, r1
    cmp r2, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    ldrb r1, [r5, #0x3]
    bl func_020676e4
    ldrb r1, [r5, #0x3]
    mov r0, r7
    bl func_020676e4
    add r1, r5, #0x4
    add r4, r1, r0
    ldr r0, [r6, #0xc]
    ldrb r1, [r7, #0x5]
    cmp r0, #0x0
    beq L_0206778c
    ldr r2, =func_020677f0
    mov r3, #0x0
    str r2, [sp, #0x0]
    mov r2, #0x8
    str r3, [sp, #0x4]
    bl func_020e4600
L_0206778c:
    str r0, [r7, #0x0]
    ldrb r1, [r7, #0x5]
    ldr r2, [r6, #0xc]
    mov r0, #0x0
    mov r1, r1, lsl #0x3
    add r1, r1, #0x8
    add r1, r2, r1
    str r1, [r6, #0xc]
    ldrb r1, [r7, #0x5]
    cmp r1, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r3, r4, r5, r6, r7, pc}
L_020677bc:
    ldr r2, [r7, #0x0]
    add r1, r5, r0
    add r2, r2, r0, lsl #0x3
    str r4, [r2, #0x4]
    ldrb r2, [r1, #0x4]
    ldrb r1, [r7, #0x5]
    add r0, r0, #0x1
    add r4, r4, r2
    cmp r0, r1
    blo L_020677bc
    add sp, sp, #0x8
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
