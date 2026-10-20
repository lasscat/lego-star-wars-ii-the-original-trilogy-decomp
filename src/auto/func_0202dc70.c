#include "m2c.h"

extern s32 func_02062a7c(s32, s32);
extern s32 func_0205e80c(s32, s32, s32);
extern void func_020327ec(s32, s32, s32);

// clang-format off
asm void func_0202dc70(s32 a0, s32 a1, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r1
    mov r7, r0
    mov r5, r2
    cmp r6, #0x1
    beq L_0202dc94
    cmp r6, #0x2
    beq L_0202dcac
    b L_0202dcc0
L_0202dc94:
    mov r0, #0xc8
    mov r1, #0x12c
    bl func_02062a7c
    mov r0, r0, lsl #0x10
    mov r4, r0, lsr #0x10
    b L_0202dcc0
L_0202dcac:
    mov r0, #0xa
    mov r1, #0x3c
    bl func_02062a7c
    mov r0, r0, lsl #0x10
    mov r4, r0, lsr #0x10
L_0202dcc0:
    mov r0, #0x20
    mov r1, #0x1
    mov r2, #0x4
    bl func_0205e80c
    cmp r0, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
    cmp r6, #0x1
    movne r5, #0x0
    cmp r5, #0x0
    movne r3, #0x1
    moveq r3, #0x0
    mov r1, r7
    mov r2, r4
    bl func_020327ec
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
