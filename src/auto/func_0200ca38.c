#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0200ca38(s32 a0) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r4, #0x0
    mov r5, r0
    mov lr, r4
    mov r1, #0x38
    mvn r3, #0x0
L_0200ca50:
    strb lr, [r5, #0x1df]
    add r2, r5, #0x100
    ldrsb ip, [r2, #0xe1]
    add r4, r4, #0x1
    add r5, r5, #0x28
    cmp ip, r3
    mlane r2, ip, r1, r0
    strneb lr, [r2, #0x3cd]
    cmp r4, #0xc
    blo L_0200ca50
    ldmfd sp!, {r3, r4, r5, pc}
}
// clang-format on
