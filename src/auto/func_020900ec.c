#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020900ec(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r4, lr}
    mov r4, #0x0
    cmp r1, #0x0
    ldmlsia sp!, {r4, pc}
    mov r0, #0x1
L_02090100:
    ldrb lr, [r2, r4]
    add r4, r4, #0x1
    cmp lr, #0xff
    ldrne ip, [r3, #0x0]
    orrne ip, ip, r0, lsl lr
    strne ip, [r3, #0x0]
    cmp r4, r1
    blo L_02090100
    ldmfd sp!, {r4, pc}
}
// clang-format on
