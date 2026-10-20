#include "m2c.h"

extern void func_02067ca0(s32, s32, s32, s32);

// clang-format off
asm s32 func_0206cf14(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    ldr r2, [r0, #0x78]
    mov r4, #0x0
    sub r2, r2, r1
    str r2, [r0, #0x78]
    ldr r2, [r0, #0x7c]
    add r3, r2, r1
    str r3, [r0, #0x7c]
    ldr r1, [r0, #0x70]
    ldr r2, [r0, #0x78]
    add r1, r1, #0x8
    sub r2, r3, r2
    cmp r2, r1
    movgt r4, #0x1
    cmp r3, #0xff
    blt L_0206cf6c
    mov r1, #0x0
    str r1, [r0, #0x78]
    mov r1, #0xff
    str r1, [r0, #0x7c]
    mov r4, #0x1
L_0206cf6c:
    mov r1, #0xff
    str r1, [sp, #0x0]
    ldr r1, [r0, #0x78]
    ldr r2, [r0, #0x7c]
    add r0, r0, #0x4c
    and r1, r1, #0xff
    and r3, r2, #0xff
    mov r2, #0x0
    bl func_02067ca0
    mov r0, r4
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, pc}
}
// clang-format on
