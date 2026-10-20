#include "m2c.h"

extern void func_020531d8();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_0205357c(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r3, lr}
    bl      func_020531d8
    ldrh r1, [sp, #0xc]
    strh r1, [r0, #0x0]
    ldr r1, [r0, #0x34]
    orr r1, r1, #0x4
    str r1, [r0, #0x34]
    ldmfd   sp!, {r3, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
