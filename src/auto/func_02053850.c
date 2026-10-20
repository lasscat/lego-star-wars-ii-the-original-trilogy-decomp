#include "m2c.h"

extern void func_020531d8();
extern void lr();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_02053850(s32 a0) {
    stmdb   sp!, {r0, r1, r2, r3}
    stmdb   sp!, {r4, lr}
    mov r4, r0
    bl      func_020531d8
    ldrh r1, [sp, #0xc]
    strh r1, [r0, #0x1c]
    mov r0, r4
    bl      func_020531d8
    ldr r1, [r0, #0x4]
    orr r1, r1, #0x1
    str r1, [r0, #0x4]
    ldmfd   sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
