#include "m2c.h"

extern void func_0201811c();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02018010(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov r2, r1
    add r0, sp, #0x2
    mov r1, r4
    mov r3, #0x0
    bl      func_0201811c
    ldrh r1, [r4, #0xca]
    ldrh r0, [sp, #0x2]
    strh r1, [sp, #0x0]
    sub r0, r0, r1
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    mov r0, r0, lsl #0x10
    movs r0, r0, asr #0x10
    rsbmi r0, r0, #0x0
    ldrh r1, [sp, #0x18]
    mov r0, r0, lsl #0x10
    cmp r1, r0, lsr #0x10
    movhi r0, #0x1
    movls r0, #0x0
    add sp, sp, #0x4
    ldmfd   sp!, {r3, r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
