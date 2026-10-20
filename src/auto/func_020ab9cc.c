#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020ab9cc(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    ldrh r0, [r1, #0x0]
    mov r5, #0x0
    add r0, r1, r0
    str r0, [sp, #0x0]
    ldrb r0, [r0, #0x1]
    cmp r0, #0x0
    bls L_020abac4
L_020ab9ec:
    ldr r0, [sp, #0x0]
    ldrh r3, [r2, #0x42]
    ldrh r6, [r0, #0x6]
    add r7, r2, #0x3c
    ldrh r4, [r7, r3]
    ldrh r0, [r0, r6]
    add r7, r7, r3
    mul lr, r4, r5
    mul r3, r0, r5
    ldr r0, [sp, #0x0]
    add r4, r7, #0x4
    add r0, r0, r6
    add r6, r0, #0x4
    ldrh r0, [r6, r3]
    ldr r8, [r4, lr]
    ldr r9, [r2, #0x8]
    and r8, r8, #0x1c000000
    mov r7, r9, lsl #0x10
    cmp r8, #0x14000000
    add r9, r1, r0
    ldreq r0, [r2, #0x18]
    mov r8, r7, lsr #0x10
    moveq r0, r0, lsl #0x10
    add r6, r6, r3
    moveq r8, r0, lsr #0x10
    ldrb r0, [r6, #0x2]
    mov r7, #0x0
    cmp r0, #0x0
    ble L_020abab0
    ldr r11, =0xc00f0000
    add ip, r1, #0x4
L_020aba68:
    ldrh r10, [r1, #0xa]
    ldrb r3, [r9, r7]
    add r7, r7, #0x1
    add r0, ip, r10
    ldrh r10, [ip, r10]
    mla r0, r10, r3, r0
    ldr r0, [r0, #0x4]
    add r3, r1, r0
    ldr r0, [r3, #0x14]
    and r0, r0, r11
    str r0, [r3, #0x14]
    ldr r10, [r4, lr]
    add r10, r10, r8
    orr r0, r0, r10
    str r0, [r3, #0x14]
    ldrb r0, [r6, #0x2]
    cmp r7, r0
    blt L_020aba68
L_020abab0:
    ldr r0, [sp, #0x0]
    add r5, r5, #0x1
    ldrb r0, [r0, #0x1]
    cmp r5, r0
    blo L_020ab9ec
L_020abac4:
    mov r0, #0x1
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
}
// clang-format on
