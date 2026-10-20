#include "m2c.h"

extern u32 data_0210ecf4[];
extern u32 data_020ff9b4[];
extern u32 data_020f88c4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c0204(s32 a0, s32 a1) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x14
    ldr r9, [r1, #0x4c]
    ldr r2, =data_0210ecf4
    mov r3, r9, lsl #0x4
    ldrh r3, [r2, r3]
    ldr r8, [r0, #0x28]
    ldr r4, =data_020ff9b4
    mov r5, r3, asr #0x4
    mov r6, r5, lsl #0x1
    add r5, r6, #0x1
    ldr r11, =data_020f88c4
    mov r7, r5, lsl #0x1
    mov r10, r6, lsl #0x1
    add r9, r2, r9, lsl #0x4
    ldmfd r4, {r2, r5, r6}
    cmp r8, #0x0
    ldrsh r7, [r11, r7]
    ldrsh r4, [r11, r10]
    beq L_020c026c
    cmp r8, #0x1
    beq L_020c029c
    cmp r8, #0x2
    beq L_020c02cc
    b L_020c02f8
L_020c026c:
    ldr r6, [r9, #0x8]
    smull r5, r8, r7, r6
    adds r10, r5, #0x800
    smull r5, r6, r4, r6
    adc r8, r8, #0x0
    adds r7, r5, #0x800
    mov r5, r10, lsr #0xc
    adc r4, r6, #0x0
    mov r6, r7, lsr #0xc
    orr r5, r5, r8, lsl #0x14
    orr r6, r6, r4, lsl #0x14
    b L_020c02f8
L_020c029c:
    ldr r6, [r9, #0x8]
    smull r2, r8, r7, r6
    adds r10, r2, #0x800
    smull r2, r6, r4, r6
    adc r8, r8, #0x0
    adds r7, r2, #0x800
    mov r2, r10, lsr #0xc
    adc r4, r6, #0x0
    mov r6, r7, lsr #0xc
    orr r2, r2, r8, lsl #0x14
    orr r6, r6, r4, lsl #0x14
    b L_020c02f8
L_020c02cc:
    ldr r5, [r9, #0x8]
    smull r2, r8, r7, r5
    adds r10, r2, #0x800
    smull r2, r5, r4, r5
    adc r8, r8, #0x0
    adds r7, r2, #0x800
    mov r2, r10, lsr #0xc
    adc r4, r5, #0x0
    mov r5, r7, lsr #0xc
    orr r2, r2, r8, lsl #0x14
    orr r5, r5, r4, lsl #0x14
L_020c02f8:
    ldrh r7, [r0, #0x24]
    ldr r8, [sp, #0x40]
    mov r10, #0x0
    smull r4, r0, r7, r8
    adds r4, r4, #0x800
    adc r0, r0, #0x0
    mov r4, r4, lsr #0xc
    orr r4, r4, r0, lsl #0x14
    strh r4, [sp, #0x6]
    ldrh r7, [sp, #0x6]
    smull r4, lr, r6, r8
    add r0, r3, r7
    strh r0, [sp, #0x0]
    ldrh r6, [sp, #0x0]
    smull ip, r3, r5, r8
    strh r6, [r9, #0x0]
    ldr r5, [r9, #0xc]
    smull r0, r11, r2, r8
    strh r7, [sp, #0x4]
    smull r7, r2, r5, r8
    adds r7, r7, #0x800
    adc r5, r2, #0x0
    adds r2, r4, #0x800
    mov r4, r7, lsr #0xc
    adc r8, lr, #0x0
    adds r7, ip, #0x800
    mov ip, r2, lsr #0xc
    mov r2, r7, lsr #0xc
    adc r3, r3, #0x0
    ldr r7, [r9, #0x8]
    orr r4, r4, r5, lsl #0x14
    add r4, r7, r4
    str r4, [r9, #0x8]
    adds r0, r0, #0x800
    strh r6, [sp, #0x2]
    mov r7, r0, lsr #0xc
    adc r6, r11, #0x0
    ldr r5, [r1, #0x2c]
    ldr r4, [r1, #0x28]
    orr r2, r2, r3, lsl #0x14
    orr ip, ip, r8, lsl #0x14
    ldr r0, [r1, #0x24]
    add r3, r5, ip
    add r2, r4, r2
    orr r7, r7, r6, lsl #0x14
    add r4, r0, r7
    str r4, [sp, #0x8]
    str r2, [sp, #0xc]
    str r3, [sp, #0x10]
    ldr r0, [r1, #0x24]
    cmp r0, r4
    ldreq r0, [r1, #0x28]
    cmpeq r0, r2
    ldreq r0, [r1, #0x2c]
    cmpeq r0, r3
    movne r10, #0x1
    cmp r10, #0x0
    addeq sp, sp, #0x14
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    addeq sp, sp, #0x10
    bxeq lr
    add r0, sp, #0x8
    add r2, r1, #0x24
    cmp r2, r0
    beq L_020c0410
    str r4, [r1, #0x24]
    ldr r0, [sp, #0xc]
    str r0, [r1, #0x28]
    ldr r0, [sp, #0x10]
    str r0, [r1, #0x2c]
L_020c0410:
    mov r0, #0x1
    strb r0, [r1, #0x45]
    add sp, sp, #0x14
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
