#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205a3b0(s32 a0, s32 a1, s32 a2, s32 a3) {
    stmdb sp!, {r3, lr}
    add ip, r0, r1, lsl #0x5
    mov lr, #0x0
L_0205a3bc:
    mov r0, lr, lsl #0x1
    ldrh r1, [ip, r0]
    add r0, ip, lr, lsl #0x1
    add lr, lr, #0x2
    strh r1, [r2, #0x0]
    ldrh r0, [r0, #0x2]
    cmp lr, #0x10
    strh r0, [r2, #0x2]
    add r2, r2, r3, lsl #0x1
    blt L_0205a3bc
    ldmfd sp!, {r3, pc}
}
// clang-format on
