#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02086e1c(s32 a0, s32 a1) {
    stmdb sp!, {r3, lr}
    add r0, r0, #0x11c
    and ip, r1, #0x1f
    mov lr, #0x1
    add r2, r0, #0x4400
    mov r3, r1, asr #0x5
    mvn r0, lr, lsl ip
    ldr r1, [r2, r3, lsl #0x2]
    and r1, r1, r0
    orr r0, r1, lr, lsl ip
    str r0, [r2, r3, lsl #0x2]
    ldmfd sp!, {r3, pc}
}
// clang-format on
