#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0208f60c(s32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x10
    ldr r1, [r0, #0x0]
    ldr r2, [r1, #0xdc]
    ldrh r1, [r2, #0xe]
    add r1, r2, r1
    ldr r1, [r1, #0xc]
    add r1, r2, r1
    ldrsh r5, [r1, #0x30]
    ldr r2, [r1, #0x38]
    ldrsh r4, [r1, #0x2e]
    ldrsh r3, [r1, #0x2c]
    str r2, [sp, #0xc]
    str r2, [sp, #0x0]
    stmib r0, {r3, r4, r5}
    ldr r3, [r0, #0x4]
    str r2, [sp, #0x4]
    smull r5, r4, r3, r2
    adds r5, r5, #0x800
    adc r3, r4, #0x0
    mov r4, r5, lsr #0xc
    orr r4, r4, r3, lsl #0x14
    str r4, [r0, #0x4]
    ldr r3, [r0, #0x8]
    str r2, [sp, #0x8]
    smull r5, r4, r3, r2
    adds r5, r5, #0x800
    adc r3, r4, #0x0
    mov r4, r5, lsr #0xc
    orr r4, r4, r3, lsl #0x14
    str r4, [r0, #0x8]
    ldr r3, [r0, #0xc]
    smull r5, r4, r3, r2
    adds r5, r5, #0x800
    adc r3, r4, #0x0
    mov r4, r5, lsr #0xc
    orr r4, r4, r3, lsl #0x14
    str r4, [r0, #0xc]
    ldrsh r4, [r1, #0x32]
    ldrsh r6, [r1, #0x34]
    ldrsh r1, [r1, #0x36]
    smull r3, lr, r4, r2
    adds r5, r3, #0x800
    smull r3, ip, r6, r2
    adc r4, lr, #0x0
    adds lr, r3, #0x800
    smull r3, r2, r1, r2
    adc r1, ip, #0x0
    mov r5, r5, lsr #0xc
    orr r5, r5, r4, lsl #0x14
    mov ip, lr, lsr #0xc
    adds r3, r3, #0x800
    orr ip, ip, r1, lsl #0x14
    str r5, [r0, #0x10]
    adc r1, r2, #0x0
    mov r2, r3, lsr #0xc
    str ip, [r0, #0x14]
    orr r2, r2, r1, lsl #0x14
    str r2, [r0, #0x18]
    ldr r2, [r0, #0x10]
    ldr r1, [r0, #0x4]
    add r1, r2, r1
    str r1, [r0, #0x10]
    ldr r2, [r0, #0x14]
    ldr r1, [r0, #0x8]
    add r1, r2, r1
    str r1, [r0, #0x14]
    ldr r2, [r0, #0x18]
    ldr r1, [r0, #0xc]
    add r1, r2, r1
    str r1, [r0, #0x18]
    add sp, sp, #0x10
    ldmfd sp!, {r4, r5, r6, pc}
}
// clang-format on
