#include "m2c.h"

extern s32 func_02066708(s32 a0);
extern s32 func_020658c8(s32 a0, s32 a1);
extern s32 func_02065840(s32 a0, s32 a1);
extern void func_02064b10(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02064b3c(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x4
    mov r5, r0
    mov r0, r3
    mov r4, r1
    mov r8, r2
    bl func_02066708
    mov r7, r0
    mov r0, r8
    mov r1, r7
    bl func_020658c8
    mov r6, r0
    mov r0, r8
    mov r1, r7
    bl func_02065840
    ldr r1, [sp, #0x20]
    strh r0, [sp, #0x0]
    strh r6, [sp, #0x2]
    cmp r1, #0x1
    bne L_02064ba8
    ldrsh r0, [sp, #0x0]
    ldrsh r1, [r4, #0x0]
    add r0, r0, #0x1
    add r0, r0, r0, lsr #0x1f
    sub r0, r1, r0, asr #0x1
    strh r0, [r4, #0x0]
    b L_02064bc0
L_02064ba8:
    cmp r1, #0x2
    bne L_02064bc0
    ldrsh r1, [r4, #0x0]
    ldrsh r0, [sp, #0x0]
    sub r0, r1, r0
    strh r0, [r4, #0x0]
L_02064bc0:
    add r2, sp, #0x0
    mov r0, r5
    mov r1, r4
    bl func_02064b10
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
}
// clang-format on
