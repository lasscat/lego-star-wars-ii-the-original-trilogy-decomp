#include "m2c.h"

extern u32 data_0210930c[];
extern void func_02096828();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020520e8(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0x34
    mov r6, r0
    ldrh r0, [r6, #0x8]
    ldrsh ip, [r6, #0x0]
    ldrsh r3, [r6, #0x4]
    mov     r8, r0, lsl 0xc
    mov     lr, ip, lsl 0xc
    ldrsh r7, [r6, #0x2]
    add r0, sp, #0x1c
    str r8, [sp, #0x1c]
    mov     ip, r7, lsl 0xc
    mov     r3, r3, lsl 0xc
    mov r7, sp
    str r8, [sp, #0x20]
    str r8, [sp, #0x24]
    mov r5, r1
    mov r4, r2
    ldmfd r0, {r0, r1, r2}
    stmea r7, {r0, r1, r2}
    mov r0, #0x4
    str r0, [sp, #0xc]
    and r2, r5, #0xff
    str r2, [sp, #0x10]
    and r2, r4, #0xff
    ldr     r0, =data_0210930c
    add r1, sp, #0x28
    str lr, [sp, #0x28]
    str ip, [sp, #0x2c]
    str r3, [sp, #0x30]
    str r2, [sp, #0x14]
    ldmfd r1, {r1, r2, r3}
    bl      func_02096828
    mov r1, #0x1
    strb r1, [r0, #0x2c]
    ldrb r1, [r6, #0xe]
    ldr     r2, =0xb60b60b7
    strb r1, [r0, #0x2d]
    ldrb r1, [r6, #0xc]
    strb r1, [r0, #0x1e]
    ldrb r1, [r6, #0xd]
    strb r1, [r0, #0x1f]
    ldrsh r3, [r6, #0xa]
    mov     r4, r3, lsl 0x10
    smull r1, r5, r2, r4
    add r5, r5, r3, lsl #0x10
    mov     r1, r4, lsr 0x1f
    add r5, r1, r5, asr #0x8
    strh r5, [sp, #0x1a]
    ldrh r1, [sp, #0x1a]
    strh r1, [r0, #0x2e]
    strh r1, [sp, #0x18]
    mov r0, #0x0
    add sp, sp, #0x34
    ldmia   sp!, {r3, r4, r5, r6, r7, r8, pc}
}
// clang-format on
