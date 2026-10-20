#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0205ddb0(s32 a0, s32 a1) {
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r6, r0
    cmp     r1, #0x0
    mov     r5, #0x0
    beq     L_0205de00
    mov     r4, r5
L_0205ddc8:
    add     r0, r5, #0x1
    mov     r0, r0, lsl #0x10
    mov     r5, r0, lsr #0x10
    mov     r0, r6
    ldr     r3, [r0, #0x0]
    cmp     r1, #0x0
    subne   r1, r1, #0x4
    cmp     r1, #0x0
    ldr     r3, [r3, #0x1c]
    addne   r1, r1, #0x4
    mov     r2, r4
    blx     r3
    movs    r1, r0
    bne     L_0205ddc8
L_0205de00:
    mov     r0, r5
    ldmia   sp!, {r4, r5, r6, pc}
}
// clang-format on
