#include "m2c.h"

s32 func_0205ab44(s32, s32);
void func_02059efc(s32, s32, s32);

// clang-format off
asm void func_02064cd8(s32 *a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x8
    str r0, [sp, #0x0]
    ldrh r0, [r0, #0x2]
    mov r7, r1
    str r2, [sp, #0x4]
    mov r8, r3
    bl func_0205ab44
    mov r6, r0
    ldrh r0, [r6, #0x6]
    mov r4, #0x0
    mov r5, r4
    cmp r0, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, r8, lsl #0x15
    add r0, r0, #0x6400000
    add r8, r0, r7, lsl #0x5
    add r9, r0, r7, lsl #0x6
    add r11, r6, #0xc
L_02064d28:
    add r0, r6, r5, lsl #0x1
    ldrh r1, [r0, #0xc]
    ldr r0, [sp, #0x4]
    add r7, r11, r1
    cmp r0, #0x0
    ldr r0, [sp, #0x0]
    ldrb r2, [r7, #0x2]
    ldrb r1, [r7, #0x3]
    addeq r10, r4, r8
    ldrh r0, [r0, #0x0]
    smulbb r1, r2, r1
    addne r10, r4, r9
    add r4, r4, r1, asr #0x1
    bl func_0205ab44
    ldrh r2, [r7, #0x4]
    mov r1, r10
    add r0, r0, r2
    bl func_02059efc
    ldrh r0, [r6, #0x6]
    add r5, r5, #0x1
    cmp r5, r0
    blo L_02064d28
    add sp, sp, #0x8
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
