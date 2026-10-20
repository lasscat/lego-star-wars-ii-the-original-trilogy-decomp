#include "m2c.h"

void func_02075698(s32, s32, s32);
void func_02075710(s32, s32, s32);

// clang-format off
asm void func_02075064(s32 *arg0, s32 arg1, s32 arg2, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    ldr r1, [r4, #0x8]
    add ip, r2, #0x1
    cmp r1, ip
    bhs L_020750cc
    ldr r3, [r4, #0x4]
    cmp ip, r3
    bls L_020750b0
    mov r2, #0x0
    strb r2, [sp, #0x2]
    sub r1, sp, #0x4
    strb r2, [r1, #0x0]
    ldr r2, [r1, #0x0]
    sub r1, ip, r3
    bl func_02075698
    b L_020750cc
L_020750b0:
    bhs L_020750cc
    mov r0, #0x0
    strb r0, [sp, #0x3]
    ldr r1, [r4, #0x4]
    sub r0, r3, ip
    sub r0, r1, r0
    str r0, [r4, #0x4]
L_020750cc:
    mov r2, #0x0
    strb r2, [sp, #0x0]
    ldr r1, [r4, #0x4]
    ldr r0, [r4, #0x8]
    cmp r1, r0
    bhs L_0207510c
    add r0, r1, #0x1
    str r0, [r4, #0x4]
    ldr r2, [sp, #0x14]
    ldr r1, [r4, #0x0]
    sub r0, r0, #0x1
    str r2, [r1, r0, lsl #0x2]
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
L_0207510c:
    strb r2, [sp, #0x1]
    sub r1, sp, #0x4
    and r0, r2, #0xff
    strb r0, [r1, #0x0]
    ldr r2, [r1, #0x0]
    add r1, sp, #0x14
    mov r0, r4
    bl func_02075710
    add sp, sp, #0x4
    ldmia sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
