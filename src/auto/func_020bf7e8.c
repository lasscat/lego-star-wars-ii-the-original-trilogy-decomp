#include "m2c.h"

extern void FX_Div();

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020bf7e8(s32 a0) {
    stmdb   sp!, {r3, r4, lr}
    sub sp, sp, #0x4
    mov r4, r0
    mov     r1, r1, lsl 0xc
    mov r0, #0x1000
    bl      FX_Div
    mov     r1, r0, asr 0x1f
    mov     r2, r1, lsl 0x1c
    mov r1, #0x800
    adds r1, r1, r0, lsl #0x1c
    orr r2, r2, r0, lsr #0x4
    adc r0, r2, #0x0
    mov     r1, r1, lsr 0xc
    orr r1, r1, r0, lsl #0x14
    strh r1, [sp, #0x2]
    ldrh r0, [sp, #0x2]
    strh r0, [sp, #0x0]
    strh r0, [r4, #0x24]
    add sp, sp, #0x4
    ldmia   sp!, {r3, r4, pc}
}
// clang-format on
