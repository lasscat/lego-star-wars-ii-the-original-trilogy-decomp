#include "m2c.h"

extern void func_0202732c();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02027470(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, lr}
    sub sp, sp, #0x8
    mov r5, r1
    mov r4, r0
    bl      func_0202732c
    ldrh r1, [r5, #0xca]
    ldrh r0, [sp, #0x20]
    strh r1, [sp, #0x2]
    sub r0, r0, r1
    strh r0, [sp, #0x4]
    ldrh r0, [sp, #0x4]
    ldrsh r2, [sp, #0x4]
    strh r0, [sp, #0x0]
    strh r0, [r4, #0x0]
    cmp r2, #0x0
    ldr     r0, =0x5555
    rsblt r2, r2, #0x0
    cmp r2, r0
    movgt r0, #0x0
    movle r0, #0x1
    strb r0, [r4, #0x2]
    mov r0, #0x64
    strb r0, [r4, #0x4]
    strb r0, [r4, #0x5]
    add sp, sp, #0x8
    ldmfd   sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
