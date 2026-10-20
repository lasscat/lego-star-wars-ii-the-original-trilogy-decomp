#include "m2c.h"

extern void func_02042cdc();
extern void func_02028fb0();
extern u32 data_0210930c[];
extern void func_0200d6d0();
extern void func_01ff97c4();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0204301c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    sub sp, sp, #0x58
    add r1, sp, #0x68
    mov ip, #0x8000
    mov r3, #0x0
    ldr r2, [r1, #0x0]
    mov r4, r0
    rsb ip, ip, #0x0
    add r0, sp, #0x34
    add r1, sp, #0x28
    str ip, [sp, #0x4]
    str r3, [sp, #0x10]
    str r3, [sp, #0x14]
    str r3, [sp, #0x18]
    str r3, [sp, #0x28]
    str r3, [sp, #0x2c]
    str r3, [sp, #0x30]
    bl      func_02042cdc
    ldrh r1, [sp, #0x64]
    sub r2, sp, #0x4
    add r0, sp, #0x40
    strh r1, [r2, #0x0]
    ldr r2, [r2, #0x0]
    add r1, sp, #0x34
    bl      func_02028fb0
    ldr     r0, =data_0210930c
    add r1, sp, #0x4
    ldr r3, [r0, #0x68]
    ldr r2, [r1, #0x0]
    ldr ip, [r4, #0x8]
    ldr r0, [sp, #0x48]
    ldr r1, [r4, #0x4]
    add ip, ip, r0
    ldr r0, [sp, #0x44]
    ldr r4, [r4, #0x0]
    add r0, r1, r0
    ldr r1, [sp, #0x40]
    str r0, [sp, #0x50]
    add r1, r4, r1
    str r1, [sp, #0x4c]
    str ip, [sp, #0x54]
    add r0, sp, #0x1c
    add r1, sp, #0x10
    ldr r4, [r3, #0x384]
    bl      func_0200d6d0
    mov r0, #0x0
    str r0, [sp, #0x0]
    mov r1, r4
    add r0, sp, #0x8
    add r2, sp, #0x4c
    add r3, sp, #0x1c
    bl      func_01ff97c4
    add r0, sp, #0x8
    ldr r0, [r0, #0x4]
    cmp r0, #0x2000
    movge r0, #0x1
    movlt r0, #0x0
    add sp, sp, #0x58
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
