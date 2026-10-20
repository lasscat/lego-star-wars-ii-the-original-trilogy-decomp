#include "m2c.h"

extern M2C_UNK HuffTreeTop[];

void func_020d0438(s32, s32);

// clang-format off
asm void func_020d0438(s32 a0, s32 a1) {
    stmdb sp!, {r4, lr}
    mov r3, #0x18
    mul r2, r0, r3
    ldr r0, =HuffTreeTop
    mul r4, r1, r3
    ldr r1, [r0, #0xc]
    add r3, r1, #0xc
    ldrh r1, [r3, r2]
    add r1, r1, #0x1
    strh r1, [r3, r2]
    ldr r1, [r0, #0xc]
    add r3, r1, #0xc
    ldrh r1, [r3, r4]
    add r1, r1, #0x1
    strh r1, [r3, r4]
    ldr r0, [r0, #0xc]
    add r1, r0, r2
    ldrh r0, [r1, #0xe]
    cmp r0, #0x0
    beq L_020d0494
    ldrh r0, [r1, #0x8]
    ldrh r1, [r1, #0xa]
    bl func_020d0438
L_020d0494:
    ldr r0, =HuffTreeTop
    ldr r0, [r0, #0xc]
    add r1, r0, r4
    ldrh r0, [r1, #0xe]
    cmp r0, #0x0
    ldmeqia sp!, {r4, pc}
    ldrh r0, [r1, #0x8]
    ldrh r1, [r1, #0xa]
    bl func_020d0438
    ldmia sp!, {r4, pc}
}
// clang-format on
