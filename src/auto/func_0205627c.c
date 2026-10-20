#include "m2c.h"

s32 func_02067080(s32, s32);
void func_02098440(s32, s32);

// clang-format off
asm void func_0205627c(s32 *arg0, s32 *arg1) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x10
    mov r5, r1
    ldrb r1, [r5, #0x6]
    ldrb r2, [r5, #0x7]
    bl func_02067080
    movs r4, r0
    addeq sp, sp, #0x10
    ldmeqia sp!, {r3, r4, r5, pc}
    ldrsh r2, [r5, #0x4]
    ldrsh r0, [r5, #0x2]
    ldrsh r1, [r5, #0x0]
    mov r3, r2, lsl #0xc
    mov r2, r0, lsl #0xc
    mov r0, r1, lsl #0xc
    str r2, [sp, #0x8]
    str r3, [sp, #0xc]
    str r0, [sp, #0x4]
    ldr r0, [r4, #0xb0]
    add ip, sp, #0x4
    cmp r0, r1, lsl #0xc
    ldreq r0, [r4, #0xb4]
    cmpeq r0, r2
    ldreq r0, [r4, #0xb8]
    cmpeq r0, r3
    movne r0, #0x1
    moveq r0, #0x0
    cmp r0, #0x0
    beq L_0205631c
    add r0, r4, #0xb0
    cmp r0, ip
    beq L_02056314
    ldr r0, [ip, #0x0]
    str r0, [r4, #0xb0]
    ldr r0, [ip, #0x4]
    str r0, [r4, #0xb4]
    ldr r0, [ip, #0x8]
    str r0, [r4, #0xb8]
L_02056314:
    mov r0, #0x1
    strb r0, [r4, #0xd1]
L_0205631c:
    ldrb r1, [r5, #0x8]
    add r0, sp, #0x2
    bl func_02098440
    ldrh r1, [sp, #0x2]
    ldrh r0, [r4, #0xca]
    strh r1, [sp, #0x0]
    cmp r0, r1
    strneh r1, [r4, #0xca]
    movne r0, #0x1
    strneb r0, [r4, #0xd0]
    add sp, sp, #0x10
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
