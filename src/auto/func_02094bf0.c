#include "m2c.h"

extern s32 func_02062a7c(s32, s32);
extern s32 func_020949b8(s32, s32, s32, s32);

// clang-format off
asm void func_02094bf0(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0xc
    mov r5, r0
    mov r8, r1
    mov r0, #0x1
    mov r1, #0x4
    mov r4, r2
    mov r7, r3
    bl func_02062a7c
    mov r6, r0
    mvn r0, #0x4
    mov r1, #0x5
    bl func_02062a7c
    ldmia r8, {r1, r3, ip}
    add r0, r1, r0, lsl #0xc
    add r3, r3, r6, lsl #0xc
    str r3, [sp, #0x4]
    str r0, [sp, #0x0]
    mov r2, r7
    mov r0, r5
    add r1, sp, #0x0
    mov r3, #0x1
    str ip, [sp, #0x8]
    bl func_020949b8
    add r1, r0, #0xc
    cmp r1, r4
    beq L_02094c74
    ldr r1, [r4, #0x0]
    str r1, [r0, #0xc]
    ldr r1, [r4, #0x4]
    str r1, [r0, #0x10]
    ldr r1, [r4, #0x8]
    str r1, [r0, #0x14]
L_02094c74:
    ldrb r1, [r5, #0xf7]
    cmp r1, #0x0
    movne r1, #0x0
    strne r1, [r0, #0x10]
    ldrh r2, [r0, #0x20]
    mov r1, #0x96
    orr r2, r2, #0x8
    strh r2, [r0, #0x20]
    strb r1, [r0, #0x22]
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
}
// clang-format on
