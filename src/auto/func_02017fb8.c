#include "m2c.h"

extern void func_02018010();
extern void func_0200aef8();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02017fb8(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, r4, r5, lr}
    ldrh r2, [sp, #0x1c]
    sub r3, sp, #0x4
    mov r5, r0
    strh r2, [r3, #0x0]
    ldr r2, [r3, #0x0]
    mov r4, r1
    bl      func_02018010
    cmp r0, #0x0
    moveq r0, #0x0
    ldmeqfd   sp!, {r3, r4, r5, lr}
    addeq sp, sp, #0x10
    bxeq lr
    add r1, sp, #0x18
    ldr r2, [r1, #0x0]
    add r0, r5, #0xb0
    add r1, r4, #0xb0
    bl      func_0200aef8
    ldmfd   sp!, {r3, r4, r5, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
