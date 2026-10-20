#include "m2c.h"

void NNSi_G3dGetTexPatAnmDataByIdx(s32, s32);

// clang-format off
asm void NNSi_G3dGetTexPatAnmFV(s32 *arg0, s32 arg1, s32 arg2) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    mov r4, r2
    bl NNSi_G3dGetTexPatAnmDataByIdx
    ldrsh r1, [r0, #0x4]
    ldrh r3, [r0, #0x6]
    mul r2, r1, r4
    add r3, r5, r3
    mov r2, r2, lsr #0xc
    b L_020c664c
L_020c6648:
    sub r2, r2, #0x1
L_020c664c:
    cmp r2, #0x0
    beq L_020c6664
    mov r1, r2, lsl #0x2
    ldrh r1, [r3, r1]
    cmp r1, r4
    bhs L_020c6648
L_020c6664:
    ldrh r1, [r0, #0x0]
    b L_020c6670
L_020c666c:
    add r2, r2, #0x1
L_020c6670:
    add r0, r2, #0x1
    cmp r0, r1
    bhs L_020c668c
    add r0, r3, r2, lsl #0x2
    ldrh r0, [r0, #0x4]
    cmp r0, r4
    bls L_020c666c
L_020c668c:
    add r0, r3, r2, lsl #0x2
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
