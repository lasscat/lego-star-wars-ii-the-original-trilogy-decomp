#include "m2c.h"

extern void func_0205e860(s32);

// clang-format off
asm void func_0205e8d0(s32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r4, r0
    ldrh r0, [r4, #0x4]
    mov r5, #0x0
    cmp r0, #0x0
    bls L_0205e914
L_0205e8e8:
    ldr r0, [r4, #0x0]
    ldr r0, [r0, r5, lsl #0x2]
    cmp r0, #0x0
    beq L_0205e904
    ldr r1, [r0, #0x0]
    ldr r1, [r1, #0x4]
    blx r1
L_0205e904:
    ldrh r0, [r4, #0x4]
    add r5, r5, #0x1
    cmp r5, r0
    blo L_0205e8e8
L_0205e914:
    ldr r0, [r4, #0x0]
    cmp r0, #0x0
    beq L_0205e92c
    bl func_0205e860
    mov r0, #0x0
    str r0, [r4, #0x0]
L_0205e92c:
    mov r0, #0x0
    strh r0, [r4, #0x4]
    ldmia sp!, {r3, r4, r5, pc}
}
// clang-format on
