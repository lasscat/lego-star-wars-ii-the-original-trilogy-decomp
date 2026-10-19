#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void _deq(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_020e29f4
    cmn ip, r3, lsl #0x1
    bhs L_020e2a08
L_020e29b8:
    orrs ip, r3, r1
    bmi L_020e29dc
    cmp r1, r3
    cmpeq r0, r2
    bx lr
L_020e29cc:
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
L_020e29dc:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
L_020e29f4:
    bne L_020e29cc
    cmp r0, #0x0
    bhi L_020e29cc
    cmn ip, r3, lsl #0x1
    blo L_020e29b8
L_020e2a08:
    bne L_020e29cc
    cmp r2, #0x0
    bhi L_020e29cc
    b L_020e29b8
}
// clang-format on
