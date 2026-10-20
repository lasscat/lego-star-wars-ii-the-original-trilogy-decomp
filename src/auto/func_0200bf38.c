#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200bf38(s32 a0, s32 a1) {
    ldr     ip, [r1, #0x0]
    ldr     r2, [r0, #0xb0]
    cmp     r2, ip
    ldreq   r3, [r0, #0xb4]
    ldreq   r2, [r1, #0x4]
    cmpeq   r3, r2
    ldreq   r3, [r0, #0xb8]
    ldreq   r2, [r1, #0x8]
    cmpeq   r3, r2
    movne   r2, #0x1
    moveq   r2, #0x0
    cmp     r2, #0x0
    beq     L_0200bf94
    add     r2, r0, #0xb0
    cmp     r2, r1
    beq     L_0200bf8c
    str     ip, [r0, #0xb0]
    ldr     r2, [r1, #0x4]
    str     r2, [r0, #0xb4]
    ldr     r2, [r1, #0x8]
    str     r2, [r0, #0xb8]
L_0200bf8c:
    mov     r2, #0x1
    strb    r2, [r0, #0xd1]
L_0200bf94:
    ldr     r0, [r0, #0x1c8]
    add     r2, r0, #0x4
    cmp     r2, r1
    bxeq    lr
    ldr     r0, [r1, #0x0]
    str     r0, [r2, #0x0]
    ldr     r0, [r1, #0x4]
    str     r0, [r2, #0x4]
    ldr     r0, [r1, #0x8]
    str     r0, [r2, #0x8]
    bx      lr
}
// clang-format on
