#include "m2c.h"

extern u32 data_020ff4cc[];
extern u32 data_020f1f9c[];
extern u32 data_020ff4dc[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208d8cc(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r5, #0x0
L_0208d8d4:
    ldr r2, =data_020ff4cc
    mvn r8, #0x0
    ldr r4, [r2, r5, lsl #0x2]
    mov r3, #0x0
    ldrh r2, [r4, #0x0]
    cmp r2, #0x28
    beq L_0208d924
L_0208d8f0:
    mov r2, r3, lsl #0x1
    ldrh r2, [r4, r2]
    cmp r0, r2
    moveq r2, r5, lsl #0x10
    moveq r8, r2, asr #0x10
    beq L_0208d924
    add r2, r3, #0x1
    mov r2, r2, lsl #0x10
    mov r3, r2, lsr #0x10
    mov r2, r3, lsl #0x1
    ldrh r2, [r4, r2]
    cmp r2, #0x28
    bne L_0208d8f0
L_0208d924:
    mov r6, #0x0
    ldr r2, =data_020f1f9c
    ldr ip, =data_020ff4dc
    mov r3, r6
    mvn r4, #0x0
    mov lr, r6
L_0208d93c:
    ldr r10, [ip, r6, lsl #0x2]
    mov r9, r4
    ldrh r11, [r10, #0x0]
    mov r7, lr
    cmp r11, #0xfa
    beq L_0208d988
L_0208d954:
    mov r11, r7, lsl #0x1
    ldrh r11, [r10, r11]
    cmp r1, r11
    moveq r7, r6, lsl #0x10
    moveq r9, r7, asr #0x10
    beq L_0208d988
    add r7, r7, #0x1
    mov r7, r7, lsl #0x10
    mov r7, r7, lsr #0x10
    mov r11, r7, lsl #0x1
    ldrh r11, [r10, r11]
    cmp r11, #0xfa
    bne L_0208d954
L_0208d988:
    cmp r8, r4
    cmpne r9, r4
    beq L_0208d9d0
    mov r7, r3
L_0208d998:
    ldrb r10, [r2, r7, lsl #0x1]
    mov r11, r7, lsl #0x1
    cmp r8, r10
    addeq r10, r2, r11
    ldreqb r10, [r10, #0x1]
    cmpeq r9, r10
    moveq r0, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    add r7, r7, #0x1
    mov r7, r7, lsl #0x10
    mov r7, r7, lsr #0x10
    ldrb r10, [r2, r7, lsl #0x1]
    cmp r10, #0x4
    bne L_0208d998
L_0208d9d0:
    add r6, r6, #0x1
    mov r6, r6, lsl #0x10
    mov r6, r6, lsr #0x10
    cmp r6, #0x7
    blo L_0208d93c
    add r2, r5, #0x1
    mov r2, r2, lsl #0x10
    mov r5, r2, lsr #0x10
    cmp r5, #0x4
    blo L_0208d8d4
    mov r0, #0x1
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
