#include "m2c.h"

extern s32 data_027e02a8;
extern s32 data_02102900;
extern s32 data_0210794c;

extern void func_020b04f0(s32, s32, s32, s32);
extern void func_02060158(s32, s32, s32, s32);

// clang-format off
asm void func_0205910c(s32 a0, s32 a1) {
    stmdb sp!, {r3, lr}
    sub sp, sp, #0x20
    ldr r0, =data_027e02a8
    ldr r0, [r0, #0x0]
    tst r0, #0x40
    beq L_02059168
    ldr r0, =data_02102900
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    ldrne r0, [r0, #0x4]
    moveq r0, #0x0
    cmp r0, #0x4
    addne sp, sp, #0x20
    ldmneia sp!, {r3, pc}
    ldrb ip, [r1, #0x0]
    ldr r0, =data_0210794c
    add r2, sp, #0x4
    mov r1, #0x32
    mov r3, #0xff
    strb ip, [sp, #0x4]
    bl func_020b04f0
    add sp, sp, #0x20
    ldmia sp!, {r3, pc}
L_02059168:
    ldr r0, =data_02102900
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    ldrne r0, [r0, #0x4]
    moveq r0, #0x0
    cmp r0, #0x4
    addne sp, sp, #0x20
    ldmneia sp!, {r3, pc}
    ldrb ip, [r1, #0x0]
    ldr r0, =data_02102900
    mov r1, #0x0
    mov r2, #0x19
    mov r3, #0x1
    str ip, [sp, #0x0]
    bl func_02060158
    add sp, sp, #0x20
    ldmia sp!, {r3, pc}
}
// clang-format on
