#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02093a00(s32 a0) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    ldr r3, [r0, #0x960]
    cmp r3, #0x0
    ldmeqia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r4, [r0, #0x958]
    ldr r1, [r0, #0x95c]
    mov r2, #0x1
    cmp r4, r1
    movgt r2, #0x0
    add r1, r4, r3
    str r1, [r0, #0x958]
    cmp r2, #0x0
    beq L_02093a44
    ldr r3, [r0, #0x95c]
    ldr r1, [r0, #0x958]
    cmp r1, r3
    bge L_02093a5c
L_02093a44:
    cmp r2, #0x0
    bne L_02093a68
    ldr r3, [r0, #0x95c]
    ldr r1, [r0, #0x958]
    cmp r1, r3
    bgt L_02093a68
L_02093a5c:
    str r3, [r0, #0x958]
    mov r1, #0x0
    str r1, [r0, #0x960]
L_02093a68:
    ldr r2, [r0, #0x5c]
    mov r1, #0x0
    ldrb r2, [r2, #0x0]
    cmp r2, #0x0
    ldmlsia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
    mov r3, #0x800
    add r2, r0, #0x60
    mov ip, r1
    mov r5, r1
    mov r4, r3
    mov r7, r1
    mov r6, r3
L_02093a98:
    ldrh r9, [r2, #0x0]
    ldr r8, [r0, #0x958]
    add r1, r1, #0x1
    mov r10, r9, lsl #0x11
    mov r10, r10, lsr #0x1b
    mov r10, r10, lsl #0xc
    smull lr, r8, r10, r8
    adds r10, lr, r3
    adc r8, r8, ip
    mov r10, r10, lsr #0xc
    orr r10, r10, r8, lsl #0x14
    mov lr, r10, lsl #0x4
    mov r8, lr, lsr #0x10
    bic r9, r9, #0x7c00
    mov r8, r8, lsl #0x1b
    orr r8, r9, r8, lsr #0x11
    strh r8, [r2, #0x0]
    ldrh r9, [r2, #0x0]
    ldr r8, [r0, #0x958]
    mov r10, r9, lsl #0x16
    mov r10, r10, lsr #0x1b
    mov r10, r10, lsl #0xc
    smull lr, r8, r10, r8
    adds r10, lr, r4
    adc r8, r8, r5
    mov r10, r10, lsr #0xc
    orr r10, r10, r8, lsl #0x14
    bic r9, r9, #0x3e0
    mov lr, r10, lsl #0x4
    mov r8, lr, lsr #0x10
    mov r8, r8, lsl #0x1b
    orr r8, r9, r8, lsr #0x16
    strh r8, [r2, #0x0]
    ldrh lr, [r2, #0x0]
    ldr r8, [r0, #0x958]
    mov r9, lr, lsl #0x1b
    mov r9, r9, lsr #0x1b
    mov r9, r9, lsl #0xc
    smull r10, r8, r9, r8
    adds r9, r10, r6
    adc r8, r8, r7
    mov r9, r9, lsr #0xc
    orr r9, r9, r8, lsl #0x14
    bic r8, lr, #0x1f
    mov lr, r9, lsl #0x4
    mov lr, lr, lsr #0x10
    and lr, lr, #0x1f
    orr r8, r8, lr
    strh r8, [r2], #0x2
    ldr lr, [r0, #0x5c]
    ldrb lr, [lr, #0x0]
    cmp r1, lr
    blo L_02093a98
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
