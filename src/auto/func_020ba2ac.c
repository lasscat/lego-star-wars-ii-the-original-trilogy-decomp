#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020ba2ac(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xc
    ldr r7, [sp, #0x30]
    add r6, sp, #0x4
    mov r5, #0x0
    add r4, sp, #0x0
    strh r5, [r6, #0x0]
    strh r5, [r6, #0x2]
    strh r5, [r6, #0x4]
    strh r5, [r4, #0x0]
    strh r5, [r4, #0x2]
    cmp r7, #0x0
    beq L_020ba308
    ldrsh r4, [r7, #0x4]
    strh r4, [sp, #0x4]
    ldrsh r4, [r7, #0x2]
    strh r4, [sp, #0x6]
    ldrsh r4, [r7, #0x0]
    strh r4, [sp, #0x8]
    ldrsh r4, [r7, #0x8]
    strh r4, [sp, #0x0]
    ldrsh r4, [r7, #0x6]
    strh r4, [sp, #0x2]
L_020ba308:
    cmp r2, #0x0
    mov r10, #0x0
    addls sp, sp, #0xc
    ldmlsia sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov ip, #0x8000
    rsb ip, ip, #0x0
    mov r11, ip, lsr #0x11
L_020ba324:
    mov r4, r10, lsl #0x1
    ldrsh r9, [r0, r4]
    ldrsh r8, [sp, #0x6]
    ldrsh r7, [sp, #0x4]
    ldrsh lr, [sp, #0x0]
    strh r8, [sp, #0x8]
    strh r7, [sp, #0x6]
    strh r9, [sp, #0x4]
    ldrsh r5, [r3, #0x2]
    ldrsh r6, [r3, #0x0]
    ldrsh r4, [r3, #0x4]
    smulbb r5, r5, r7
    smlabb r5, r6, r9, r5
    smlabb r7, r4, r8, r5
    ldrsh r6, [r3, #0x6]
    ldrsh r5, [r3, #0x8]
    ldrsh r4, [sp, #0x2]
    smlabb r6, r6, lr, r7
    smlabb r4, r5, r4, r6
    mov r4, r4, asr #0xe
    cmp r4, #0x8000
    movge r4, r11
    bge L_020ba388
    cmp r4, ip
    movlt r4, ip
L_020ba388:
    mov r4, r4, lsl #0x10
    mov r5, r10, lsl #0x1
    mov r6, r4, asr #0x10
    strh r6, [r1, r5]
    ldrsh r4, [sp, #0x0]
    add r10, r10, #0x1
    cmp r10, r2
    strh r4, [sp, #0x2]
    strh r6, [sp, #0x0]
    blo L_020ba324
    add sp, sp, #0xc
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
