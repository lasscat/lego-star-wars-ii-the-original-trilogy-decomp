#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_020e2920(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_020e2980
    cmn ip, r3, lsl #0x1
    bhs L_020e2994
L_020e2934:
    orrs ip, r3, r1
    bmi L_020e2958
    cmp r1, r3
    cmpeq r0, r2
    bx lr
L_020e2948:
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
L_020e2958:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    bne L_020e2974
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bxeq lr
L_020e2974:
    cmp r3, r1
    cmpeq r2, r0
    bx lr
L_020e2980:
    bne L_020e2948
    cmp r0, #0x0
    bhi L_020e2948
    cmn ip, r3, lsl #0x1
    blo L_020e2934
L_020e2994:
    bne L_020e2948
    cmp r2, #0x0
    bhi L_020e2948
    b L_020e2934
}
// clang-format on
