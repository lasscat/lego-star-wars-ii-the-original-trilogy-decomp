#include "m2c.h"

extern M2C_UNK data_02100a74[];
extern M2C_UNK data_02100a76[];
extern M2C_UNK data_02100d98[];

s32 func_02062b10(s32);
s32 func_020b94e4(s32);
s32 func_020bb4fc(s32, s32, s32, s32, s32, s32);
s32 func_020b94fc(s32);

// clang-format off
asm s32 func_020b8fa4(s32 a0, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, lr}
    sub sp, sp, #0x10
    ldr r1, =data_02100a74
    mov r2, r0, lsl #0x2
    ldrh r0, [r1, r2]
    ldr r1, =data_02100a76
    cmp r0, #0x1
    ldrh r4, [r1, r2]
    movls r0, #0x0
    bls L_020b8fe0
    sub r0, r0, #0x1
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl func_02062b10
L_020b8fe0:
    ldr r1, =data_02100d98
    add r0, r4, r0
    add r4, r1, r0, lsl #0x2
    bl func_020b94e4
    ldrb r0, [sp, #0x1c]
    cmp r0, #0x3
    blo L_020b9014
    cmp r0, #0x7
    bhs L_020b9014
    ldr r0, [sp, #0x24]
    cmp r0, #0x0
    ldreqh r0, [r4, #0x2]
    streq r0, [sp, #0x24]
L_020b9014:
    add r0, sp, #0x1c
    mov r3, sp
    ldmia r0, {r0, r1, r2}
    stmia r3, {r0, r1, r2}
    ldr r0, [sp, #0x28]
    mov r2, #0xff
    str r0, [sp, #0xc]
    ldrh r0, [r4, #0x0]
    ldrh r1, [r4, #0x2]
    mov r3, r2
    bl func_020bb4fc
    mov r4, r0
    bl func_020b94fc
    mov r0, r4
    add sp, sp, #0x10
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
