#include "m2c.h"

extern s32 func_020c93c8(s32);

// clang-format off
asm void func_020bb964(s32 a0, s32 a1) {
    stmdb sp!, {r4, r5, lr}
    sub sp, sp, #0xc
    ldr r2, [r1, #0x0]
    mov r5, r0
    cmp r2, #0x0
    ldr r1, =0x15180
    bge L_020bb98c
    add r0, r2, #0x80000000
    bl func_020c93c8
    b L_020bb998
L_020bb98c:
    add r0, r2, #0x7f
    add r0, r0, #0x2d00
    bl func_020c93c8
L_020bb998:
    mov r4, r0
    mov r0, r4
    mov r1, #0xe10
    bl func_020c93c8
    ldr r2, =0x91a2b3c5
    ldr r3, =0x88888889
    smull r1, ip, r2, r4
    smull r1, r2, r3, r0
    add ip, r4, ip
    mov r1, r4, lsr #0x1f
    add ip, r1, ip, asr #0xb
    add r2, r0, r2
    mov r1, r0, lsr #0x1f
    add r2, r1, r2, asr #0x5
    mov r1, #0x3c
    str ip, [sp, #0x0]
    str r2, [sp, #0x4]
    bl func_020c93c8
    add r1, sp, #0x0
    str r0, [sp, #0x8]
    ldmia r1, {r0, r1, r2}
    stmia r5, {r0, r1, r2}
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, pc}
}
// clang-format on
