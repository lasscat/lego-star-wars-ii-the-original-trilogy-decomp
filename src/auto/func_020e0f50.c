#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020e0f50(s32 a0, s32 a1) {
    cmp     r0, #0x0
    beq     L_020e0f68
    ldr     r3, [r0, #0x4]
    mov     r2, r3, lsl #0x16
    movs    r2, r2, lsr #0x1d
    bne     L_020e0f70
L_020e0f68:
    mov     r0, #0x0
    bx      lr
L_020e0f70:
    mov     r2, r3, lsl #0x14
    movs    r2, r2, lsr #0x1e
    beq     L_020e0f90
    cmp     r2, #0x1
    beq     L_020e0fb8
    cmp     r2, #0x2
    moveq   r1, #0x1
    b       L_020e0fbc
L_020e0f90:
    cmp     r1, #0x0
    ble     L_020e0fa8
    bic     r2, r3, #0xc00
    orr     r2, r2, #0x800
    str     r2, [r0, #0x4]
    b       L_020e0fbc
L_020e0fa8:
    biclt   r2, r3, #0xc00
    orrlt   r2, r2, #0x400
    strlt   r2, [r0, #0x4]
    b       L_020e0fbc
L_020e0fb8:
    mvn     r1, #0x0
L_020e0fbc:
    mov     r0, r1
    bx      lr
}
// clang-format on
