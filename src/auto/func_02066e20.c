#include "m2c.h"

extern void func_02066ec4(s32);
extern s32 func_020e4600(s32, s32, s32, s32, s32);

// clang-format off
asm void func_02066e20(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x8
    mov r5, r0
    add r0, r5, #0xc00
    mov r4, r1
    ldrh r1, [r0, #0x16]
    cmp r1, #0x0
    addeq sp, sp, #0x8
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r0, [r5, #0xc]
    cmp r0, #0x0
    beq L_02066e68
    ldr r2, =func_02066ec4
    mov r3, #0x0
    str r2, [sp, #0x0]
    mov r2, #0x4
    str r3, [sp, #0x4]
    bl func_020e4600
L_02066e68:
    str r0, [r5, #0x0]
    add r0, r5, #0xc00
    ldrh r1, [r0, #0x16]
    ldr r2, [r5, #0xc]
    mov r3, #0x0
    mov r1, r1, lsl #0x2
    add r1, r1, #0x8
    add r1, r2, r1
    str r1, [r5, #0xc]
    ldrh r1, [r0, #0x16]
    cmp r1, #0x0
    addls sp, sp, #0x8
    ldmlsia sp!, {r3, r4, r5, pc}
L_02066e9c:
    ldr r1, [r5, #0x0]
    str r4, [r1, r3, lsl #0x2]
    ldrh r1, [r0, #0x16]
    add r3, r3, #0x1
    add r4, r4, #0x10
    cmp r3, r1
    blo L_02066e9c
    add sp, sp, #0x8
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
