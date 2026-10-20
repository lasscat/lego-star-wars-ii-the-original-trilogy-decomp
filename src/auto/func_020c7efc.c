#include "m2c.h"

extern void FX_DivAsync();
extern void func_020c930c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020c7efc(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r5, r1
    ldrh r2, [r5, #0x2c]
    ldrh r1, [r5, #0x2e]
    mov r6, r0
    mov r4, r2, lsl #0xc
    mov r7, r1, lsl #0xc
    mov r0, r7
    mov r1, r4
    bl      FX_DivAsync
    ldrsh r0, [r5, #0x22]
    str r0, [r6, #0x0]
    str r0, [r6, #0x14]
    bl      func_020c930c
    ldrsh r2, [r5, #0x20]
    mov r1, r7
    rsb r2, r2, #0x0
    mul r0, r2, r0
    mov r2, r0, asr #0xc
    mov r0, r4
    str r2, [r6, #0x4]
    bl      FX_DivAsync
    ldrsh r1, [r5, #0x20]
    ldrsh r0, [r5, #0x22]
    ldrh r3, [r5, #0x2c]
    add r2, r1, r0
    rsb r2, r2, #0x0
    add r2, r2, #0x1000
    mul r2, r3, r2
    mov r2, r2, lsl #0x3
    str r2, [r6, #0x30]
    sub r0, r1, r0
    ldrh r1, [r5, #0x2e]
    add r0, r0, #0x1000
    mul r0, r1, r0
    mov r0, r0, lsl #0x3
    str r0, [r6, #0x34]
    bl      func_020c930c
    ldrsh r1, [r5, #0x20]
    mul r0, r1, r0
    mov r0, r0, asr #0xc
    str r0, [r6, #0x10]
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
