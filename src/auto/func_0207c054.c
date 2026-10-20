#include "m2c.h"

extern s32 data_02104d90;
extern s32 data_02102900;

extern s32 func_02086534(s32, s32);
extern void func_0205ecc4(s32, s32, s32, s32, s32);
extern void func_020601ac(s32, s32, s32, s32, s32);

// clang-format off
asm void func_0207c054(s32 a0) {
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x8
    mov r4, r0
    ldrb r0, [r4, #0xdd]
    ldrb r1, [r4, #0xdc]
    cmp r0, #0x0
    bne L_0207c0bc
    ldr r0, =data_02104d90
    add r1, r1, #0x49
    bl func_02086534
    mov r2, #0x0
    str r2, [sp, #0x0]
    str r2, [sp, #0x4]
    ldrb r3, [r4, #0xdc]
    ldr r0, =data_02102900
    mov r1, #0x9
    bl func_0205ecc4
    mov r3, #0x0
    str r3, [sp, #0x0]
    ldr r0, =data_02102900
    mov r1, #0xa
    mov r2, #0x1
    str r3, [sp, #0x4]
    bl func_0205ecc4
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
L_0207c0bc:
    ldr r0, =data_02104d90
    add r1, r1, #0x49
    bl func_02086534
    cmp r0, #0x0
    moveq r0, #0x0
    addeq sp, sp, #0x8
    streqb r0, [r4, #0xdf]
    ldmeqia sp!, {r4, pc}
    mov r1, #0x2
    mov r2, #0x35
    str r1, [sp, #0x0]
    mov ip, #0x0
    ldr r0, =data_02102900
    sub r3, r2, #0x36
    mov r1, #0x1
    str ip, [sp, #0x4]
    bl func_020601ac
    mov r0, #0x0
    strb r0, [r4, #0xde]
    add sp, sp, #0x8
    ldmia sp!, {r4, pc}
}
// clang-format on
