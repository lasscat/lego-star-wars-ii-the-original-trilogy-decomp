#include "m2c.h"

extern u32 data_020eedac[];

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_02076cb0(s32 a0) {
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r4, #0x0
    ldr     ip, =data_020eedac
    mov     lr, r4
    mov     r1, #0x14
L_02076cc4:
    mul     r3, r4, r1
    strb    lr, [r0, lr]
    ldrb    r2, [ip, r3]
    add     r5, r0, lr
    add     r3, ip, r3
    cmp     r2, #0x6
    bne     L_02076cf0
L_02076ce0:
    ldrb    r2, [r3, #0x14]!
    add     r4, r4, #0x1
    cmp     r2, #0x6
    beq     L_02076ce0
L_02076cf0:
    strb    r4, [r5, #0x7]
    strb    lr, [r5, #0xe]
    add     lr, lr, #0x1
    cmp     lr, #0x7
    add     r4, r4, #0x1
    blt     L_02076cc4
    mov     r3, #0x0
    mov     r2, r3
L_02076d10:
    add     r1, r0, r3
    add     r3, r3, #0x1
    strb    r2, [r1, #0x15]
    cmp     r3, #0x6
    blt     L_02076d10
    ldmfd   sp!, {r3, r4, r5, pc}
}
// clang-format on
