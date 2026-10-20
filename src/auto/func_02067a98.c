#include "m2c.h"

extern u8 data_020f716c[];
extern void func_02055e98(s32, s32, s32);

// clang-format off
asm void func_02067a98(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    ldr r2, [r0, #0x0]
    ldr r8, [r0, #0x4]
    ldrb r7, [r2, #0x0]
    mov r5, r1
    add r4, r2, #0x1
    mov r9, #0x0
    cmp r7, #0x0
    ldmlsia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
    ldr r6, =data_020f716c
L_02067ac0:
    ldrb r10, [r4], #0x1
    mov r1, r5
    mov r2, r8
    mov r0, r10
    bl func_02055e98
    ldrb r0, [r6, r10]
    add r9, r9, #0x1
    cmp r9, r7
    add r8, r8, r0
    blo L_02067ac0
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
