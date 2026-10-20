#include "m2c.h"

extern u32 data_02101b78[];
extern void func_02053ee8();
extern void func_02053f44();
extern void func_020534e0();
extern u32 data_020edec0[];
extern void func_020534f4();
extern void func_02054c80();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0206e7b4(s32 a0) {
    stmdb   sp!, {r3, lr}
    sub sp, sp, #0x30
    mov r1, #0x0
    ldr     r0, =data_02101b78
    mov r2, r1
    bl      func_02053ee8
    ldr     r0, =data_02101b78
    mov r1, #0x1000
    bl      func_02053f44
    add r0, sp, #0x28
    bl      func_020534e0
    ldr     r0, =data_020edec0
    sub r3, sp, #0x4
    ldrh r2, [r0, #0x0]
    add r0, sp, #0x28
    mov r1, #0x0
    strh r2, [r3, #0x0]
    ldr r3, [r3, #0x0]
    mov r2, #0x1
    bl      func_020534f4
    mov r3, #0x0
    strh r3, [sp, #0x1c]
    strh r3, [sp, #0x1e]
    str r3, [sp, #0x0]
    str r3, [sp, #0x4]
    str r3, [sp, #0x8]
    mov r0, #0x10
    str r0, [sp, #0xc]
    add r0, sp, #0x1c
    str r0, [sp, #0x10]
    strb r3, [sp, #0x14]
    strb r3, [sp, #0x15]
    strb r3, [sp, #0x16]
    ldr     r2, =0x1398
    add r0, sp, #0x20
    add r1, sp, #0x28
    strb r3, [sp, #0x18]
    strb r3, [sp, #0x19]
    strb r3, [sp, #0x1a]
    strb r3, [sp, #0x1b]
    strb r3, [sp, #0x17]
    bl      func_02054c80
    add sp, sp, #0x30
    ldmia   sp!, {r3, pc}
}
// clang-format on
