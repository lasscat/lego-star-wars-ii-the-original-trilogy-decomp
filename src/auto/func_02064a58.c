#include "m2c.h"

extern u32 data_021044a4[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02064a58(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldrsh r4, [r1, #0x0]
    mov r3, #0x0
    cmp r4, #0x0
    ldrnesh r2, [r1, #0x2]
    cmpne r2, #0x0
    movne r3, #0x1
    cmp r3, #0x0
    beq      L_02064aec
    ldrh ip, [r0, #0x4]
    mov r2, r4, lsl #0x10
    mov r3, r2, lsr #0x10
    cmp ip, r2, lsr #0x10
    ldrh r5, [r0, #0xa]
    ldrh r4, [r0, #0x8]
    ldrh lr, [r0, #0x6]
    ldrh r2, [r1, #0x2]
    bhi      L_02064aec
    add r1, ip, r4
    cmp r3, r1
    bge      L_02064aec
    cmp r2, lr
    blo      L_02064aec
    add r1, lr, r5
    cmp r2, r1
    bge      L_02064aec
    ldr     r1, =data_021044a4
    ldrb r1, [r1, #0x0]
    mov r1, r1, lsl #0x1b
    movs r1, r1, lsr #0x1f
    movne r1, #0x1
    moveq r1, #0x0
    strb r1, [r0, #0x1]
    ldrh r1, [r0, #0x2]
    add r1, r1, #0x1
    strh r1, [r0, #0x2]
    b      L_02064af8
    L_02064aec:
    mov r1, #0x0
    strb r1, [r0, #0x1]
    strh r1, [r0, #0x2]
    L_02064af8:
    ldrh r0, [r0, #0x2]
    cmp r0, #0x0
    movne r0, #0x1
    moveq r0, #0x0
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
