#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020b3280(s32 a0, s32 a1) {
    cmp r1, #0x45
    addls pc, pc, r1, lsl #0x2
    b L_020b33ac
L_020b328c:
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33ac
    b L_020b33a4
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33a4
    b L_020b33ac
    b L_020b33a4
    b L_020b33a4
L_020b33a4:
    mov r0, #0x1
    bx lr
L_020b33ac:
    mov r0, #0x0
    bx lr
}
// clang-format on
