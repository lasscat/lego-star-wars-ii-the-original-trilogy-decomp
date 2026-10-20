#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0206c49c(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x8
    add r3, r0, #0x800
    ldrh r4, [r3, #0x84]
    mov ip, #0x0
    str ip, [sp, #0x4]
    cmp r4, #0x2
    moveq r3, #0x3
    streq r3, [sp, #0x0]
    movne r3, #0x1
    movne r3, r3, lsl r4
    strne r3, [sp, #0x0]
L_0206c4cc:
    ldr r3, [sp, #0x0]
    add r4, ip, #0x1
    tst r4, r3
    beq L_0206c5a0
    add r3, r0, #0x800
    ldrh r3, [r3, #0x84]
    cmp r3, #0x2
    bne L_0206c510
    ldr r3, [r0, #0x70]
    cmp ip, #0x0
    moveq r3, r3, asr #5
    subeq r5, r3, #0x1
    beq L_0206c51c
    mov r3, r3, asr #5
    add r3, r3, r3, lsl #0x1
    sub r5, r3, #0x2
    b L_0206c51c
L_0206c510:
    ldr r3, [r0, #0x70]
    mov r3, r3, asr #0x4
    sub r5, r3, #0x1
L_0206c51c:
    cmp ip, r2
    moveq r3, #0x1
    movne r3, #0x0
    add r4, r3, r3, lsl #0x3
    ldr r3, [sp, #0x4]
    ldr lr, [r0, #0x74]
    add r4, r3, r4
    add r3, lr, #0x3
    cmp lr, r3
    add r6, r4, #0x13
    bge L_0206c5a0
    mov r8, lr, lsl #0x5
    add r9, r0, #0x800
    mov r11, #0x0
L_0206c554:
    add r3, r1, r8, lsl #0x1
    mov r4, r11
    add r7, r3, r5, lsl #0x1
L_0206c560:
    ldrh r3, [r9, #0x88]
    ldrh r10, [r9, #0x8a]
    add r4, r4, #0x1
    add r3, r3, #0x1
    add r10, r10, r6
    orr r3, r10, r3, lsl #0xc
    strh r3, [r7], #0x2
    cmp r4, #0x3
    add r6, r6, #0x1
    blt L_0206c560
    ldr r3, [r0, #0x74]
    add lr, lr, #0x1
    add r3, r3, #0x3
    cmp lr, r3
    add r8, r8, #0x20
    blt L_0206c554
L_0206c5a0:
    ldr r3, [sp, #0x4]
    add ip, ip, #0x1
    add r3, r3, #0x12
    cmp ip, #0x1
    str r3, [sp, #0x4]
    ble L_0206c4cc
    add sp, sp, #0x8
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
