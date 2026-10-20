#include "m2c.h"

s32 func_020c631c(s32);

// clang-format off
asm void SetPlttParamaters_(s32 *arg0, s32 arg1, s32 *arg2) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldrh r0, [r5, #0x34]
    mov r4, r2
    add r0, r5, r0
    bl func_020c631c
    ldr r1, [r5, #0x2c]
    ldrh r2, [r0, #0x2]
    mov r1, r1, lsl #0x10
    mov r1, r1, lsr #0x10
    tst r2, #0x1
    ldrh r0, [r0, #0x0]
    bne L_020c7a90
    mov r0, r0, lsl #0xf
    mov r1, r1, lsl #0xf
    mov r0, r0, lsr #0x10
    mov r1, r1, lsr #0x10
L_020c7a90:
    add r0, r0, r1
    str r0, [r4, #0x14]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
