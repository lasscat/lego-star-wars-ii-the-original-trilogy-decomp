#include "m2c.h"

extern s32 HuffTreeTop;

// clang-format off
asm s32 HuffRemainingNodeCanSetOffset(s32 a0) {
    stmdb sp!, {r4, lr}
    ldr r2, =HuffTreeTop
    rsb r0, r0, #0x40
    ldrb r1, [r2, #0x0]
    mov r0, r0, lsl #0x10
    mov r4, r0, asr #0x10
    cmp r1, #0x0
    mov lr, #0x0
    bls L_020d02a0
    ldr r0, [r2, #0x8]
    mov r3, #0x6
L_020d0228:
    mul ip, lr, r3
    ldrb r2, [r0, ip]
    add ip, r0, ip
    cmp r2, #0x0
    beq L_020d0260
    sub r2, r1, lr
    cmp r2, r4
    bgt L_020d0258
    sub r2, r4, #0x1
    mov r2, r2, lsl #0x10
    mov r4, r2, asr #0x10
    b L_020d0260
L_020d0258:
    mov r0, #0x0
    ldmia sp!, {r4, pc}
L_020d0260:
    ldrb r2, [ip, #0x1]
    cmp r2, #0x0
    beq L_020d0290
    sub r2, r1, lr
    cmp r2, r4
    bgt L_020d0288
    sub r2, r4, #0x1
    mov r2, r2, lsl #0x10
    mov r4, r2, asr #0x10
    b L_020d0290
L_020d0288:
    mov r0, #0x0
    ldmia sp!, {r4, pc}
L_020d0290:
    add r2, lr, #0x1
    and lr, r2, #0xff
    cmp lr, r1
    blo L_020d0228
L_020d02a0:
    mov r0, #0x1
    ldmia sp!, {r4, pc}
}
// clang-format on
