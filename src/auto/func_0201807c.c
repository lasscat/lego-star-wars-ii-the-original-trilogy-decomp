#include "m2c.h"

extern s32 func_020985d8(s32, s32);

// clang-format off
asm void func_0201807c(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    sub sp, sp, #0x20
    ldr r7, [r2, #0x8]
    ldr r6, [r1, #0xb8]
    ldr ip, [r1, #0xb4]
    ldmia r2, {r5, lr}
    ldr r4, [r1, #0xb0]
    sub r6, r7, r6
    sub r5, r5, r4
    sub ip, lr, ip
    mov r4, r0
    str r5, [sp, #0x14]
    str ip, [sp, #0x18]
    str r6, [sp, #0x1c]
    cmp r3, #0x0
    beq L_020180fc
    ldr r5, [r1, #0xb8]
    ldr ip, [r1, #0xb4]
    ldmia r2, {r0, r3, lr}
    ldr r1, [r1, #0xb0]
    sub r5, r5, lr
    sub r2, r1, r0
    sub r3, ip, r3
    add r1, sp, #0x14
    add r0, sp, #0x8
    cmp r1, r0
    str r2, [sp, #0x8]
    str r3, [sp, #0xc]
    str r5, [sp, #0x10]
    strne r2, [sp, #0x14]
    strne r3, [sp, #0x18]
    strne r5, [sp, #0x1c]
L_020180fc:
    ldr r1, [sp, #0x1c]
    ldr r0, [sp, #0x14]
    str r1, [sp, #0x4]
    str r0, [sp, #0x0]
    bl func_020985d8
    strh r0, [r4, #0x0]
    add sp, sp, #0x20
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
