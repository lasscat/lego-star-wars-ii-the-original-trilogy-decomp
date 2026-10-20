#include "m2c.h"

s32 func_020c631c(s32, s32, s32);
void func_020c3f2c(s32, s32);

// clang-format off
asm s32 func_020c3fc4(s32 *a0, s32 *a1) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    ldr r2, [r0, #0x8]
    mov r10, r1
    add r8, r0, r2
    ldrh r0, [r8, #0x2]
    mov r7, #0x1
    mov r6, #0x0
    add r5, r8, r0
    ldrb r0, [r5, #0x1]
    cmp r0, #0x0
    bls L_020c4068
    mov r9, r6
    mov r4, r6
L_020c3ff8:
    ldrh r1, [r5, #0x6]
    ldrh r0, [r10, #0x34]
    add r2, r5, r1
    ldrh r1, [r2, #0x2]
    add r0, r10, r0
    add r1, r2, r1
    add r1, r1, r9
    bl func_020c631c
    movs r3, r0
    beq L_020c4050
    ldrh r1, [r5, #0x6]
    ldrh r0, [r5, r1]
    add r1, r5, r1
    add r1, r1, #0x4
    mla r1, r0, r6, r1
    ldrb r0, [r1, #0x3]
    tst r0, #0x1
    bne L_020c4054
    mov r0, r8
    mov r2, r10
    bl func_020c3f2c
    b L_020c4054
L_020c4050:
    mov r7, r4
L_020c4054:
    ldrb r0, [r5, #0x1]
    add r6, r6, #0x1
    add r9, r9, #0x10
    cmp r6, r0
    blo L_020c3ff8
L_020c4068:
    mov r0, r7
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
// clang-format on
