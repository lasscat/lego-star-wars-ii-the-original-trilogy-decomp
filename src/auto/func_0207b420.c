#include "m2c.h"

extern void clearDataAndInstructionCache(s32, s32);

// clang-format off
asm void func_0207b420(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r5, =0x66666667
    mov r2, r1, lsr #0x1f
    smull r3, r4, r5, r1
    mov r5, r0
    ldr ip, [r5, #0x40]
    add r4, r2, r4, asr #0x1
    mov r3, #0x5
    smull r0, r2, r3, r4
    cmp r1, ip
    sub r4, r1, r0
    bge L_0207b480
    ldr r0, [r5, #0x44]
    add r2, r5, r4, lsl #0x2
    ldr r1, [r0, r1, lsl #0x2]
    ldr r0, [r2, #0x1c]
    add r1, r1, #0x2
    bl clearDataAndInstructionCache
    add r0, r5, r4, lsl #0x2
    ldr r1, [r0, #0x1c]
    ldr r0, [r1, #0x8]
    orr r0, r0, #0x1
    str r0, [r1, #0x8]
    ldmia sp!, {r3, r4, r5, pc}
L_0207b480:
    add r0, r5, r4, lsl #0x2
    ldr r1, [r0, #0x1c]
    ldr r0, [r1, #0x8]
    bic r0, r0, #0x1
    str r0, [r1, #0x8]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
