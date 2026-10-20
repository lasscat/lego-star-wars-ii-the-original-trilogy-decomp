#include "m2c.h"

extern u32 data_021044a4[];
extern u32 data_020edf94[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020724e0(s32 a0, s32 a1) {
    stmdb   sp!, {r3, lr}
    ldr     r0, =data_021044a4
    ldrb    r2, [r0, #0x0]
    mov     r2, r2, lsl #0x1b
    movs    r2, r2, lsr #0x1f
    beq     L_02072550
    ldr     r3, =data_020edf94
    mov     r2, r1, lsl #0x3
    ldrh    lr, [r0, #0x2a]
    ldrh    r2, [r3, r2]
    add     r3, r3, r1, lsl #0x3
    ldrh    r1, [r0, #0x2c]
    cmp     lr, r2
    ldrh    ip, [r3, #0x6]
    ldrh    r0, [r3, #0x4]
    ldrh    r3, [r3, #0x2]
    blo     L_02072550
    add     r0, r2, r0
    cmp     lr, r0
    bge     L_02072550
    mov     r0, r1, lsl #0x10
    cmp     r3, r0, lsr #0x10
    mov     r1, r0, lsr #0x10
    bhi     L_02072550
    add     r0, r3, ip
    cmp     r1, r0
    movlt   r0, #0x1
    ldmltia sp!, {r3, pc}
L_02072550:
    mov     r0, #0x0
    ldmfd   sp!, {r3, pc}
}
// clang-format on
