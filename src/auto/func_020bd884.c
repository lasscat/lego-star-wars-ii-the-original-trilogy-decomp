#include "m2c.h"

s32 FX_Div(s32, s32);

// clang-format off
asm void func_020bd884(s32 *obj, s32 a1, s32 a2, ...) {
    stmdb sp!, {r0, r1, r2, r3}
    stmdb sp!, {r4, lr}
    mov r4, r0
    ldrb r1, [r4, #0x4]
    cmp r1, #0x0
    ldmeqia sp!, {r4, lr}
    addeq sp, sp, #0x10
    bxeq lr
    cmp r2, #0x0
    beq L_020bd8cc
    cmp r1, #0x1
    bls L_020bd8cc
    sub r1, r1, #0x1
    ldr r0, [sp, #0xc]
    mov r1, r1, lsl #0xc
    bl FX_Div
    str r0, [r4, #0x0]
    b L_020bd8dc
L_020bd8cc:
    ldr r0, [sp, #0xc]
    mov r1, r1, lsl #0xc
    bl FX_Div
    str r0, [r4, #0x0]
L_020bd8dc:
    ldrb r0, [r4, #0x7]
    tst r0, #0x2
    beq L_020bd8f8
    ldrb r0, [r4, #0x4]
    mov r0, r0, asr #0x1
    strb r0, [r4, #0x5]
    b L_020bd914
L_020bd8f8:
    tst r0, #0x4
    moveq r0, #0x0
    streqb r0, [r4, #0x5]
    beq L_020bd914
    ldrb r0, [r4, #0x4]
    sub r0, r0, #0x1
    strb r0, [r4, #0x5]
L_020bd914:
    ldrb r0, [r4, #0x7]
    tst r0, #0x4
    orrne r0, r0, #0x10
    biceq r0, r0, #0x10
    strb r0, [r4, #0x7]
    ldrb r0, [r4, #0x7]
    bic r0, r0, #0x20
    strb r0, [r4, #0x7]
    ldmia sp!, {r4, lr}
    add sp, sp, #0x10
    bx lr
}
// clang-format on
