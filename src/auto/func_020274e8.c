#include "m2c.h"

extern void func_0202732c();
extern void func_020985d8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020274e8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, lr}
    sub sp, sp, #0x1c
    mov r4, r1
    mov r6, r2
    mov r5, r0
    bl      func_0202732c
    ldr r1, [r6, #0x8]
    ldr r0, [r4, #0xb8]
    ldr r3, [r4, #0xb4]
    sub r1, r1, r0
    ldmfd r6, {r2, ip}
    ldr r0, [r4, #0xb0]
    sub r3, ip, r3
    sub r0, r2, r0
    str r0, [sp, #0x10]
    str r3, [sp, #0x14]
    str r1, [sp, #0x18]
    str r1, [sp, #0xc]
    str r0, [sp, #0x8]
    bl      func_020985d8
    ldrh r1, [r4, #0xca]
    mov     r0, r0, lsl 0x10
    rsb r0, r1, r0, lsr #0x10
    strh r0, [sp, #0x4]
    ldrh r0, [sp, #0x4]
    ldrsh r2, [sp, #0x4]
    strh r1, [sp, #0x2]
    strh r0, [sp, #0x0]
    strh r0, [r5, #0x0]
    cmp r2, #0x0
    ldr     r0, =0x5555
    rsblt r2, r2, #0x0
    cmp r2, r0
    movgt r0, #0x0
    movle r0, #0x1
    strb r0, [r5, #0x2]
    mov r0, #0x64
    strb r0, [r5, #0x4]
    strb r0, [r5, #0x5]
    add sp, sp, #0x1c
    ldmia   sp!, {r3, r4, r5, r6, pc}
}
// clang-format on
