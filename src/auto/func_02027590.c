#include "m2c.h"

extern void func_0202732c();
extern void func_020985d8();
extern void func_0200f5d0();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02027590(s32 a0) {
    stmdb   sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x20
    mov r3, #0x14000
    mov r5, r1
    mov r4, r2
    mov r6, r0
    str r3, [sp, #0x10]
    bl      func_0202732c
    ldr r1, [r4, #0x8]
    ldr r0, [r5, #0xb8]
    ldr r3, [r5, #0xb4]
    sub r1, r1, r0
    ldmfd r4, {r2, ip}
    ldr r0, [r5, #0xb0]
    sub r3, ip, r3
    sub r0, r2, r0
    str r0, [sp, #0x14]
    str r3, [sp, #0x18]
    str r1, [sp, #0x1c]
    str r1, [sp, #0x8]
    str r0, [sp, #0x4]
    bl      func_020985d8
    ldrh r3, [r5, #0xca]
    mov r2, r0, lsl #0x10
    mov r1, r4
    strh r3, [sp, #0x0]
    rsb r2, r3, r2, lsr #0x10
    mov r3, #0x0
    str r3, [sp, #0xc]
    strh r2, [r6, #0x0]
    add r2, sp, #0x10
    mov r3, #0x64
    strb r3, [r6, #0x5]
    ldr r2, [r2, #0x0]
    add r0, r5, #0xb0
    add r3, sp, #0xc
    bl      func_0200f5d0
    cmp r0, #0x0
    beq      L_02027644
    ldr r0, [sp, #0xc]
    cmp r0, #0xe1000
    mov r0, #0x0
    strltb r0, [r6, #0x2]
    strgeb r0, [r6, #0x5]
    b      L_0202764c
    L_02027644:
    mov r0, #0x1
    strb r0, [r6, #0x2]
    L_0202764c:
    mov r0, #0x64
    strb r0, [r6, #0x4]
    add sp, sp, #0x20
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
