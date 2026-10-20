#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm s32 func_020b33b4(s32 a0, s32 a1) {
    cmp r1, #0x45
    addls pc, pc, r1, lsl #0x2
    b L_020b34e8
L_020b33c0:
    b L_020b34e8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e8
    b L_020b34d8
    b L_020b34d8
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34d8
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
    b L_020b34d8
    b L_020b34e0
    b L_020b34d8
    b L_020b34e0
    b L_020b34d8
    b L_020b34d8
    b L_020b34d8
    b L_020b34e0
    b L_020b34e0
    b L_020b34e0
L_020b34d8:
    mov r0, #0x0
    bx lr
L_020b34e0:
    mov r0, #0x1
    bx lr
L_020b34e8:
    mov r0, #0x0
    bx lr
}
// clang-format on
