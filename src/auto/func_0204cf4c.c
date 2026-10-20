#include "m2c.h"

extern u32 data_020ff9b4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0204cf4c(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    ldr r3, [r2, #0x0]
    mov r4, #0x0
    str r3, [sp, #0x0]
    ldr r5, [r2, #0x4]
    cmp r3, #0x0
    str r5, [sp, #0x4]
    ldr r2, [r2, #0x8]
    mov r5, #0x1
    cmpeq r2, #0x0
    moveq r5, r4
    str r2, [sp, #0x8]
    str r4, [sp, #0x4]
    cmp r5, #0x0
    beq L_0204d0d0
    cmp r3, #0x0
    ldreq r2, [sp, #0x4]
    cmpeq r2, #0x0
    ldreq r2, [sp, #0x8]
    cmpeq r2, #0x0
    bne L_0204cfd0
    ldr r4, =data_020ff9b4
    add r2, sp, #0x0
    cmp r2, r4
    beq L_0204d0d0
    ldr r3, [r4, #0x0]
    ldr r2, [r4, #0x4]
    str r3, [sp, #0x0]
    str r2, [sp, #0x4]
    ldr r2, [r4, #0x8]
    str r2, [sp, #0x8]
    b L_0204d0d0
L_0204cfd0:
    ldr r4, [sp, #0x4]
    ldr r2, [sp, #0x8]
    smull r6, r5, r4, r4
    smlal r6, r5, r3, r3
    smlal r6, r5, r2, r2
    ldr r4, =0x4000280
    mov r3, #0x2
    strh r3, [r4, #0x0]
    mov r3, #0x0
    str r3, [r4, #0x10]
    mov r3, #0x1000000
    str r3, [r4, #0x14]
    str r6, [r4, #0x18]
    mov r2, r5, lsl #0x2
    str r5, [r4, #0x1c]
    mov r3, #0x1
    strh r3, [r4, #0x30]
    mov r3, r6, lsl #0x2
    str r3, [r4, #0x38]
    orr r2, r2, r6, lsr #0x1e
    str r2, [r4, #0x3c]
L_0204d024:
    ldrh r2, [r4, #0x30]
    tst r2, #0x8000
    bne L_0204d024
    ldr r2, =0x40002b4
    ldr r10, [r2, #0x0]
    sub r3, r2, #0x34
L_0204d03c:
    ldrh r2, [r3, #0x0]
    tst r2, #0x8000
    bne L_0204d03c
    ldr r11, =0x40002a0
    ldr lr, [sp, #0x0]
    ldr r9, [r11, #0x0]
    ldr r3, [sp, #0x4]
    umull r8, r7, r9, r10
    ldr r2, [sp, #0x8]
    mov r6, r10, asr #0x1f
    umull r5, r4, r8, lr
    mov ip, lr, asr #0x1f
    mla r7, r9, r6, r7
    ldr r9, [r11, #0x4]
    mov r6, r3, asr #0x1f
    mla r7, r9, r10, r7
    mla r4, r8, ip, r4
    umull r10, r9, r8, r3
    adds r5, r5, #0x0
    mla r4, r7, lr, r4
    adc r4, r4, #0x1000
    adds r5, r10, #0x0
    mla r9, r8, r6, r9
    mla r9, r7, r3, r9
    adc r6, r9, #0x1000
    umull r3, r5, r8, r2
    adds r3, r3, #0x0
    mov r3, r4, asr #0xd
    str r3, [sp, #0x0]
    mov r3, r2, asr #0x1f
    mla r5, r8, r3, r5
    mla r5, r7, r2, r5
    adc r2, r5, #0x1000
    mov r3, r6, asr #0xd
    mov r2, r2, asr #0xd
    str r3, [sp, #0x4]
    str r2, [sp, #0x8]
L_0204d0d0:
    ldr r4, [r1, #0x28]
    ldr r3, [sp, #0x8]
    ldr r2, [sp, #0x4]
    ldr r5, [sp, #0x0]
    smull r7, r6, r3, r4
    adds r9, r7, #0x800
    smull r3, r7, r2, r4
    adc r2, r6, #0x0
    adds r8, r3, #0x800
    mov r3, r9, lsr #0xc
    smull r6, r4, r5, r4
    adc r7, r7, #0x0
    adds r6, r6, #0x800
    mov r8, r8, lsr #0xc
    adc r5, r4, #0x0
    mov r6, r6, lsr #0xc
    ldr r4, [r1, #0x4]
    orr r6, r6, r5, lsl #0x14
    ldr r5, [r1, #0xc]
    orr r3, r3, r2, lsl #0x14
    ldr r2, [r1, #0x8]
    orr r8, r8, r7, lsl #0x14
    add r1, r4, r6
    str r1, [r0, #0x0]
    add r1, r2, r8
    str r1, [r0, #0x4]
    add r1, r5, r3
    str r1, [r0, #0x8]
    add sp, sp, #0xc
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
