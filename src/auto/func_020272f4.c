#include "m2c.h"

extern void func_0200aef8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020272f4(s32 a0) {
    stmdb   sp!, {r3, lr}
    ldrb r3, [r0, #0x56]
    mvn r2, #0x0
    cmp r3, r2
    add r2, r0, r3, lsl #0x3
    ldr r3, [r0, #0x0]
    ldrb r0, [r2, #0x4]
    ldr r2, [r3, #0x0]
    ldr r0, [r2, r0, lsl #0x2]
    ldr r2, [r0, #0x20]
    add r0, r0, #0x14
    str r2, [sp, #0x0]
    bl      func_0200aef8
    ldmia   sp!, {r3, pc}
}
// clang-format on
