#include "m2c.h"

// clang-format off
asm void NNSi_GfdInitLnkVramBlockPool(s32 *arg0, s32 arg1) {
    stmdb sp!, {r4, lr}
    subs lr, r1, #0x1
    mov r2, #0x0
    beq L_020c30a0
    mov r4, r0
L_020c307c:
    add r3, r2, #0x1
    add r2, r0, r2, lsl #0x4
    add ip, r0, r3, lsl #0x4
    str ip, [r2, #0xc]
    str r4, [r2, #0x18]
    mov r2, r3
    cmp r3, lr
    add r4, r4, #0x10
    blo L_020c307c
L_020c30a0:
    mov r2, #0x0
    str r2, [r0, #0x8]
    add r1, r0, r1, lsl #0x4
    str r2, [r1, #-0x4]
    ldmia sp!, {r4, pc}
}
// clang-format on
