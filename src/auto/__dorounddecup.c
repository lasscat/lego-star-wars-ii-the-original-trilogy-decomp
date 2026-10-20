#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void __dorounddecup(s32 a0, s32 a1) {
    add     r3, r0, #0x5
    add     r1, r3, r1
    sub     ip, r1, #0x1
    mov     r1, #0x0
L_020e1390:
    ldrb    r2, [ip, #0x0]
    cmp     r2, #0x9
    addlo   r0, r2, #0x1
    strlob  r0, [ip, #0x0]
    bxlo    lr
    cmp     ip, r3
    bne     L_020e13c4
    mov     r1, #0x1
    strb    r1, [ip, #0x0]
    ldrsh   r1, [r0, #0x2]
    add     r1, r1, #0x1
    strh    r1, [r0, #0x2]
    bx      lr
L_020e13c4:
    strb    r1, [ip], #-0x1
    b       L_020e1390
}
// clang-format on
