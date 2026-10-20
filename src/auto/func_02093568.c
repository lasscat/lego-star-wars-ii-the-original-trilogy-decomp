#include "m2c.h"

extern s32 data_021027f8;
extern s32 func_02007eb4(s32, s32, s32);

// clang-format off
asm void func_02093568(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #0x4
    ldr r4, =data_021027f8
    mov r10, r0
    ldrb r6, [r4, #0x29]
    mov r0, #0x0
    movs r7, r3
    str r0, [r10, #0x0]
    strne r0, [r7, #0x0]
    cmp r6, #0x0
    mov r9, r1
    mov r8, r2
    mov r5, #0x0
    addls sp, sp, #0x4
    ldmlsia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
    add r4, sp, #0x0
L_020935a8:
    add r0, r9, r5, lsl #0x2
    ldr r2, [r0, #0x4c]
    cmp r2, #0x0
    beq L_020935e0
    mov r0, r4
    mov r1, r8
    add r2, r2, #0xb0
    bl func_02007eb4
    ldr r0, [sp, #0x0]
    cmp r7, #0x0
    str r0, [r10, #0x0]
    addne r0, r9, r5, lsl #0x2
    ldrne r0, [r0, #0x4c]
    strne r0, [r7, #0x0]
L_020935e0:
    add r5, r5, #0x1
    cmp r5, r6
    blo L_020935a8
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
