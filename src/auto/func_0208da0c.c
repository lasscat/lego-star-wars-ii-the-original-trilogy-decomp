#include "m2c.h"

extern s32 func_0208d8cc(s32);

// clang-format off
asm s32 func_0208da0c(s32 a0, u16 *a1) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r6, r0
    mov r5, r1
    mov r4, #0x0
L_0208da1c:
    add r0, r5, r4, lsl #0x1
    add r0, r0, #0x600
    ldrh r1, [r0, #0xe8]
    cmp r1, #0xfa
    beq L_0208da44
    mov r0, r6
    bl func_0208d8cc
    cmp r0, #0x0
    moveq r0, #0x0
    ldmeqia sp!, {r4, r5, r6, pc}
L_0208da44:
    add r0, r4, #0x1
    and r4, r0, #0xff
    cmp r4, #0x5
    blo L_0208da1c
    mov r0, #0x1
    ldmia sp!, {r4, r5, r6, pc}
}
// clang-format on
