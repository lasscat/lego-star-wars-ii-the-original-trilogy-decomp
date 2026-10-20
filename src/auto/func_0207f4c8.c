#include "m2c.h"

extern void func_0205e84c(s32);

// clang-format off
asm void func_0207f4c8(s32 obj) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    ldr r4, [r5, #0xc]
    cmp r4, #0x0
    beq L_0207f4f0
L_0207f4dc:
    ldr r0, [r4, #0x0]
    bl func_0205e84c
    ldr r4, [r4, #0x4]
    cmp r4, #0x0
    bne L_0207f4dc
L_0207f4f0:
    add r0, r5, #0x8
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x18]
    blx r1
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
