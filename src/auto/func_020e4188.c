#include "m2c.h"

extern void func_020e3700();
extern void func_020e4bd8();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020e4188(s32 a0) {
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov r4, r3
    mov r5, r2
    mov r2, r4
    mov r7, r0
    mov r6, r1
    bl      func_020e3700
    ldr r2, [r7, #0x18]
    ldr r1, [r5, #0x8]
    ldr r0, [r7, #0x4]
    add r3, r2, r1
    str r0, [r2, r1]
    ldr r1, [r7, #0x0]
    mov r0, r7
    str r1, [r3, #0x4]
    ldr r2, [r7, #0x8]
    mov r1, r6
    str r2, [r3, #0x8]
    str r4, [r3, #0x14]
    ldr r3, [r6, #0x0]
    ldr r2, [r5, #0x4]
    add r2, r3, r2
    bl      func_020e4bd8
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
}
// clang-format on
