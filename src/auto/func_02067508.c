#include "m2c.h"

extern void func_02067b5c(void);
extern void func_020e4600(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_02067b70(s32 a0, s32 a1, s32 a2, s32 a3);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02067508(s32 a0, s32 a1, s32 a2) {
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x8
    mov r7, r0
    mov r5, r1
    ldrh r1, [r7, #0x20]
    mov r4, r2
    cmp r1, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    ldr r0, [r5, #0xc]
    cmp r0, #0x0
    beq L_02067550
    ldr r2, =func_02067b5c
    mov r3, #0x0
    str r2, [sp, #0x0]
    mov r2, #0xc
    str r3, [sp, #0x4]
    bl func_020e4600
L_02067550:
    str r0, [r7, #0x14]
    ldrh r1, [r7, #0x20]
    mov r0, #0xc
    ldr r2, [r5, #0xc]
    mul r0, r1, r0
    add r0, r0, #0x8
    add r0, r2, r0
    str r0, [r5, #0xc]
    ldrh r0, [r7, #0x20]
    ldrh r1, [r4, #0xc]
    add r2, r4, #0x10
    cmp r0, #0x0
    add r4, r2, r1
    mov r5, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r3, r4, r5, r6, r7, pc}
    mov r6, r5
L_02067594:
    ldrb r3, [r4, #0x2]
    ldr r0, [r7, #0x14]
    ldrb r1, [r4, #0x3]
    mov r2, r4
    add r0, r0, r6
    add r3, r4, r3
    bl func_02067b70
    ldrh r1, [r4, #0x0]
    ldrh r0, [r7, #0x20]
    add r5, r5, #0x1
    add r4, r4, r1
    cmp r5, r0
    add r6, r6, #0xc
    blo L_02067594
    add sp, sp, #0x8
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
