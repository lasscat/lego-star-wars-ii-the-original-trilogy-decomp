#include "m2c.h"

extern s32 OS_GetTick(void);
extern s32 _ll_udiv(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0206763c(s32 a0);
extern void func_020675d8(s32 a0);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02090918(s32 a0) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    mov r9, r0
    mov r7, #0x0
    add r0, r9, #0x28
    ldr r5, =0x1ff6210
    add r8, r0, #0x400
    mov r10, r7
    mov r4, r7
L_02090938:
    ldrb r0, [r8, #0xd]
    cmp r0, #0x0
    beq L_020909d0
    bl OS_GetTick
    ldr r1, [r8, #0x0]
    mov r6, r0
    ldr r2, [r8, #0x8]
    sub r0, r6, r1
    sub r3, r2, r0
    mov r0, r3, asr #0x1f
    mov r1, r0, lsl #0x6
    str r3, [r8, #0x8]
    mov r2, r5
    orr r1, r1, r3, lsr #0x1a
    mov r0, r3, lsl #0x6
    mov r3, r4
    bl _ll_udiv
    str r0, [r8, #0x4]
    str r6, [r8, #0x0]
    ldr r0, [r8, #0x8]
    cmp r0, #0x0
    bgt L_020909d0
    ldrb r1, [r8, #0xf]
    cmp r1, #0x0
    beq L_020909ac
    ldr r0, [r9, #0x38c]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_0206763c
L_020909ac:
    ldrb r1, [r8, #0xe]
    cmp r1, #0x0
    beq L_020909c8
    ldr r0, [r9, #0x38c]
    ldr r0, [r0, #0x4]
    add r0, r0, #0x28
    bl func_020675d8
L_020909c8:
    strb r10, [r8, #0xd]
    strb r10, [r8, #0xc]
L_020909d0:
    add r7, r7, #0x1
    cmp r7, #0x5
    add r8, r8, #0x10
    blo L_02090938
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
