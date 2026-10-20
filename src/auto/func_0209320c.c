#include "m2c.h"

extern u32 data_02102900[];
extern u32 data_020ff54c[];

s32 func_020917b4(s32);

// clang-format off
asm void func_0209320c(s32 *arg0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    mov r1, #0x1000
    str r1, [r4, #0x958]
    str r1, [r4, #0x95c]
    mov r1, #0x0
    str r1, [r4, #0x960]
    bl func_020917b4
    cmp r0, #0x4a
    blt L_02093294
    ldr r1, =data_02102900
    ldr r2, [r1, #0x0]
    cmp r2, #0x0
    ldrne r1, [r2, #0x4]
    moveq r1, #0x0
    cmp r1, #0x11
    beq L_02093290
    cmp r2, #0x0
    moveq r1, #0x0
    beq L_02093268
    ldr r1, =data_02102900
    ldr r1, [r1, #0x0]
    ldr r1, [r1, #0x4]
L_02093268:
    cmp r1, #0x33
    beq L_02093290
    cmp r2, #0x0
    moveq r1, #0x0
    beq L_02093288
    ldr r1, =data_02102900
    ldr r1, [r1, #0x0]
    ldr r1, [r1, #0x4]
L_02093288:
    cmp r1, #0x9
    bne L_02093294
L_02093290:
    mov r0, #0x47
L_02093294:
    ldr r1, =data_020ff54c
    ldr r1, [r1, r0, lsl #0x2]
    str r1, [r4, #0x5c]
    cmp r1, #0x0
    ldmeqia sp!, {r4, pc}
    ldrb r0, [r1, #0x0]
    mov r2, #0x0
    cmp r0, #0x0
    ldmlsia sp!, {r4, pc}
L_020932b8:
    add r0, r1, r2, lsl #0x4
    ldrh r1, [r0, #0x4]
    add r0, r4, r2, lsl #0x1
    add r2, r2, #0x1
    strh r1, [r0, #0x60]
    ldr r1, [r4, #0x5c]
    ldrb r0, [r1, #0x0]
    cmp r2, r0
    blo L_020932b8
    ldmia sp!, {r4, pc}
}
// clang-format on
