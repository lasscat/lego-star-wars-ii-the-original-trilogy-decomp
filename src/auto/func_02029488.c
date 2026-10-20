#include "m2c.h"

extern void func_0205e80c();
extern void func_020accac();
extern void func_0200af90();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02029488(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x64
    movs r6, r0
    mov r5, r1
    addeq sp, sp, #0x64
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    mov r0, #0x1c0
    mov r1, #0x3
    mov r2, #0x4
    bl      func_0205e80c
    movs r4, r0
    addeq sp, sp, #0x64
    ldmeqia   sp!, {r3, r4, r5, r6, pc}
    mov r0, #0x1000
    mov lr, #0x0
    str r0, [sp, #0x10]
    str r0, [sp, #0x14]
    str r0, [sp, #0x18]
    strh lr, [sp, #0x8]
    ldrh ip, [r6, #0xca]
    add r0, sp, #0x1c
    add r2, sp, #0x8
    add r3, sp, #0x10
    add r1, r6, #0xb0
    strh ip, [sp, #0xa]
    strh lr, [sp, #0xc]
    bl      func_020accac
    mov r0, #0x0
    str r0, [sp, #0x0]
    add ip, sp, #0x1c
    mov r0, r4
    mov r2, r5
    mov r3, #0x1
    mov r1, #0x8
    str ip, [sp, #0x4]
    bl      func_0200af90
    add sp, sp, #0x64
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
