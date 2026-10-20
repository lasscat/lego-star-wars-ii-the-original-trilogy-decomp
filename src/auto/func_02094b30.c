#include "m2c.h"

extern s32 func_02062a7c(s32, s32);
extern s32 func_020949b8(s32, s32, s32, s32);

// clang-format off
asm void func_02094b30(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    mov r7, #0x0
    mov r10, r0
    mov r9, r1
    mov r8, r2
    mov r4, r7
    mov r11, #0x96
    mvn r5, #0x4
L_02094b54:
    mov r0, #0x1
    mov r1, #0x4
    bl func_02062a7c
    mov r6, r0
    mov r0, r5
    mov r1, #0x5
    bl func_02062a7c
    ldmia r9, {r1, r2, r3}
    add r0, r1, r0, lsl #0xc
    add r2, r2, r6, lsl #0xc
    str r2, [sp, #0x4]
    str r3, [sp, #0x8]
    str r0, [sp, #0x0]
    mov r0, r10
    add r1, sp, #0x0
    mov r2, #0x5
    mov r3, #0x1
    bl func_020949b8
    add r1, r0, #0xc
    cmp r1, r8
    beq L_02094bc0
    ldr r1, [r8, #0x0]
    str r1, [r0, #0xc]
    ldr r1, [r8, #0x4]
    str r1, [r0, #0x10]
    ldr r1, [r8, #0x8]
    str r1, [r0, #0x14]
L_02094bc0:
    ldrb r1, [r10, #0xf7]
    add r7, r7, #0x1
    cmp r1, #0x0
    strne r4, [r0, #0x10]
    ldrh r1, [r0, #0x20]
    cmp r7, #0x5
    orr r1, r1, #0x8
    strh r1, [r0, #0x20]
    strb r11, [r0, #0x22]
    blo L_02094b54
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
