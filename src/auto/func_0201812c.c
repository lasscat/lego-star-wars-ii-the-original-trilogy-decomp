#include "m2c.h"

s32 func_020985d8(s32, s32, s32, s32, s32, s32);

// clang-format off
asm void func_0201812c(s32 *obj, s32 *arg, s32 a2) {
    stmdb sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x24
    mov r4, r0
    ldr r6, [r1, #0x8]
    ldr lr, [r4, #0xb8]
    ldr r5, [r4, #0xb4]
    ldmia r1, {r3, ip}
    ldr r0, [r4, #0xb0]
    sub r6, r6, lr
    sub r5, ip, r5
    sub r0, r3, r0
    str r0, [sp, #0x18]
    str r5, [sp, #0x1c]
    str r6, [sp, #0x20]
    cmp r2, #0x0
    beq L_020181ac
    ldmia r1, {r0, r3, lr}
    ldr r5, [r4, #0xb8]
    ldr ip, [r4, #0xb4]
    ldr r2, [r4, #0xb0]
    sub r5, r5, lr
    sub r2, r2, r0
    sub r3, ip, r3
    add r1, sp, #0x18
    add r0, sp, #0xc
    cmp r1, r0
    str r2, [sp, #0xc]
    str r3, [sp, #0x10]
    str r5, [sp, #0x14]
    strne r2, [sp, #0x18]
    strne r3, [sp, #0x1c]
    strne r5, [sp, #0x20]
L_020181ac:
    ldr r0, [sp, #0x18]
    cmp r0, #0x0
    ldreq r0, [sp, #0x20]
    cmpeq r0, #0x0
    addeq sp, sp, #0x24
    ldmeqia sp!, {r3, r4, r5, r6, pc}
    ldr r1, [sp, #0x20]
    ldr r0, [sp, #0x18]
    str r1, [sp, #0x8]
    str r0, [sp, #0x4]
    bl func_020985d8
    strh r0, [sp, #0x2]
    ldrh r1, [sp, #0x2]
    ldrh r0, [r4, #0xca]
    strh r1, [sp, #0x0]
    cmp r0, r1
    strneh r1, [r4, #0xca]
    movne r0, #0x1
    strneb r0, [r4, #0xd0]
    add sp, sp, #0x24
    ldmia sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
