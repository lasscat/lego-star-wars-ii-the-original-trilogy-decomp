#include "m2c.h"

extern u32 data_020ff495[];
extern u32 data_020ff4a0[];
extern void _s32_div_f();
extern void func_02054c80();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0208d64c(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x28
    mov r5, r0
    ldrh r2, [r5, #0xa]
    ldr     r0, =0xffff
    cmp r2, r0
    addeq sp, sp, #0x28
    ldmeqia   sp!, {r3, r4, r5, pc}
    ldrb r2, [r5, #0x8]
    mov r0, #0x14
    mov ip, #0x0
    smulbb r3, r2, r0
    ldr     r2, =data_020ff495
    ldr     r0, =data_020ff4a0
    ldrb r4, [r2, r3]
    strb ip, [sp, #0x18]
    mul r2, r1, r4
    ldrb r1, [r0, r3]
    and r0, r2, #0xff
    bl      _s32_div_f
    mov ip, #0x0
    mov lr, #0x20
    mov r3, #0xd0
    strh ip, [sp, #0x1c]
    strh ip, [sp, #0x1e]
    mov r1, #0x1
    stmea sp, {r1, r3, ip}
    ldrb r1, [sp, #0x18]
    add r2, sp, #0x1c
    str ip, [sp, #0xc]
    str r2, [sp, #0x10]
    strb r1, [sp, #0x14]
    and r1, r0, #0xff
    strb r1, [sp, #0x15]
    strb lr, [sp, #0x16]
    strb r4, [sp, #0x17]
    strb r0, [sp, #0x19]
    ldrh r2, [r5, #0xa]
    add r0, sp, #0x20
    mov r1, r5
    add r3, r3, #0x3d
    strb lr, [sp, #0x1a]
    strb r4, [sp, #0x1b]
    bl      func_02054c80
    add sp, sp, #0x28
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
