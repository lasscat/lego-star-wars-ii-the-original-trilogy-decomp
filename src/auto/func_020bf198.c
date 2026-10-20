#include "m2c.h"

extern s32 func_020be664(s32 a0);
extern void func_020bd75c(s32 a0, s32 a1, s32 a2);

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020bf198(s32 a0) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x30
    mov r5, r0
    bl func_020be664
    mov ip, #0x0
    mov r4, r0
    str ip, [sp, #0x20]
    str ip, [sp, #0x24]
    strh ip, [sp, #0x28]
    strh ip, [sp, #0x2a]
    strh ip, [sp, #0x2c]
    strh ip, [sp, #0x2e]
    ldr r3, [r4, #0x0]
    add r0, sp, #0x14
    str r3, [sp, #0x20]
    ldrh r2, [r4, #0x4]
    add r1, sp, #0x20
    strh ip, [sp, #0x2]
    strh r2, [sp, #0x28]
    ldrh r2, [r4, #0x6]
    strh ip, [sp, #0x6]
    strh ip, [sp, #0x4]
    strh r2, [sp, #0x2c]
    str r3, [sp, #0x24]
    strh ip, [sp, #0x2a]
    strh ip, [sp, #0x0]
    strh ip, [sp, #0x2e]
    bl func_020bd75c
    add r0, sp, #0x14
    add ip, sp, #0x8
    add r3, r5, #0x14
    ldmia r0, {r0, r1, r2}
    stmia ip, {r0, r1, r2}
    cmp r3, ip
    beq L_020bf23c
    ldr r0, [sp, #0x8]
    str r0, [r5, #0x14]
    ldr r0, [sp, #0xc]
    str r0, [r5, #0x18]
    ldr r0, [sp, #0x10]
    str r0, [r5, #0x1c]
L_020bf23c:
    ldr r1, [r4, #0x8]
    add r0, r4, #0xc
    str r1, [r5, #0x20]
    add sp, sp, #0x30
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
