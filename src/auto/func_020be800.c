#include "m2c.h"

extern void FX_Div();
extern u32 data_0210e2f8[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020be800(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    ldr r2, [r0, #0x10]
    mov r4, r1
    cmp r2, #0x0
    beq      L_020be828
    ldr r2, [r0, #0xc]
    ldr r1, [r0, #0x8]
    sub r1, r2, r1
    mov r1, r1, asr #0xc
    b      L_020be864
    L_020be828:
    ldr r5, [r4, #0x74]
    ldr r2, [r0, #0x8]
    ldr r1, [r0, #0xc]
    smull r3, ip, r2, r5
    adds lr, r3, #0x800
    smull r3, r2, r1, r5
    adc r1, ip, #0x0
    adds r3, r3, #0x800
    mov ip, lr, lsr #0xc
    orr ip, ip, r1, lsl #0x14
    adc r1, r2, #0x0
    mov r2, r3, lsr #0xc
    orr r2, r2, r1, lsl #0x14
    mov r1, ip, asr #0xc
    rsb r1, r1, r2, asr #0xc
    L_020be864:
    ldr r2, [r0, #0x14]
    ldr r0, [r4, #0x30]
    mov r1, r1, lsl #0xc
    sub r0, r2, r0
    bl      FX_Div
    ldr r2, [r4, #0x4c]
    ldr     r1, =data_0210e2f8
    str r0, [r1, r2, lsl #0x2]
    ldmia   sp!, {r3, r4, r5, pc}
}
// clang-format on
