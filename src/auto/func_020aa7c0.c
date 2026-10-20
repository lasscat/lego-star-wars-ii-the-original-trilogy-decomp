#include "m2c.h"

extern void func_0205e84c(s32);

// clang-format off
asm void func_020aa7c0(s32 a0, s32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    add r0, r5, #0x394
    ldr r2, [r0, #0x0]
    mov r4, r1
    ldr r2, [r2, #0x14]
    blx r2
    cmp r0, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r0, #0x4
    str r0, [r4, #0x24]
    ldr r1, [r4, #0x0]
    cmp r1, #0x0
    addne r0, r4, #0x4
    cmpne r0, r1
    beq L_020aa818
    ldr r0, [r1, #0x0]
    str r0, [r4, #0x4]
    ldr r0, [r1, #0x4]
    str r0, [r4, #0x8]
    ldr r0, [r1, #0x8]
    str r0, [r4, #0xc]
L_020aa818:
    add r0, r4, #0x4
    str r0, [r4, #0x0]
    ldr r0, [r4, #0x1c]
    cmp r0, #0x3000
    ldmgtia sp!, {r3, r4, r5, pc}
    add r0, r5, #0x394
    ldr r2, [r0, #0x0]
    mov r1, r4
    ldr r2, [r2, #0xc]
    blx r2
    mov r0, r4
    bl func_0205e84c
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
