#include "m2c.h"

extern M2C_UNK data_02101310[];

void MIi_CpuClear16(s32, s32, s32);
s32 func_020c6458(s32, s32, s32);

// clang-format off
asm void func_020c73b4(s32 *out, s32 *arg1, s32 *arg2) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    ldr r3, =data_02101310
    ldr r4, [r2, #0x8]
    ldr r3, [r3, #0x0]
    mov r9, r0
    str r3, [r9, #0xc]
    ldrb r0, [r2, #0x18]
    mov r8, r1
    add r6, r2, r4
    strb r0, [r9, #0x19]
    mov r2, r0, lsl #0x1
    add r1, r9, #0x1a
    mov r0, #0x0
    bl MIi_CpuClear16
    ldrb r0, [r8, #0x9]
    mov r5, #0x0
    cmp r0, #0x0
    ldmlsia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
    mov r7, r5
    add r4, r8, #0x8
L_020c7404:
    ldrh r1, [r8, #0xe]
    add r0, r6, #0x4
    add r2, r4, r1
    ldrh r1, [r2, #0x2]
    add r1, r2, r1
    add r1, r1, r7
    bl func_020c6458
    cmp r0, #0x0
    orrge r1, r5, #0x100
    addge r0, r9, r0, lsl #0x1
    strgeh r1, [r0, #0x1a]
    ldrb r0, [r8, #0x9]
    add r5, r5, #0x1
    add r7, r7, #0x10
    cmp r5, r0
    blo L_020c7404
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
